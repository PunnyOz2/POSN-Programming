#include<bits/stdc++.h>
using namespace std;
char b[515][515];
int qs[515][515];
int play(int x,int y,int xx,int yy){
    if((xx-x+1)*(yy-y+1)==4){
        int cou=0;
        cou=qs[xx][yy]-qs[x-1][yy]-qs[xx][y-1]+qs[x-1][y-1];
        if(cou==4)cou=1;
        else if(cou==0)cou=1;
        else cou=0;
        return cou;
    }
    int cou=(xx-x+1)*(yy-y+1)/4;
    int Min=1<<30;
    int midx=(xx+x)/2;
    int midy=(yy+y)/2;
    int one = play(x,y,midx,midy);
    int two = play(midx+1,y,xx,midy);
    int three = play(x,midy+1,midx,yy);
    int four = play(midx+1,midy+1,xx,yy);
    int onec = qs[midx][midy]-qs[x-1][midy]-qs[midx][y-1]+qs[x-1][y-1];
    int twoc = qs[xx][midy]-qs[midx][midy]-qs[xx][y-1]+qs[midx][y-1];
    int threec = qs[midx][yy]-qs[midx][midy]-qs[x-1][yy]+qs[x-1][midy];
    int fourc = qs[xx][yy]-qs[xx][midy]-qs[midx][yy]+qs[midx][midy];
//    printf("%d %d\n",one,onec);
//    printf("%d %d\n",two,twoc);
//    printf("%d %d\n",three,threec);
//    printf("%d %d\n",four,fourc);
    Min=min(Min,one+two+cou-threec+fourc);
    Min=min(Min,one+two+cou+threec-fourc);
    Min=min(Min,one+three+cou-twoc+fourc);
    Min=min(Min,one+three+cou+twoc-fourc);
    Min=min(Min,one+four+cou-twoc+threec);
    Min=min(Min,one+four+cou+twoc-threec);
    Min=min(Min,two+three+cou-onec+fourc);
    Min=min(Min,two+three+cou+onec-fourc);
    Min=min(Min,two+four+cou-onec+threec);
    Min=min(Min,two+four+cou+onec-threec);
    Min=min(Min,three+four+cou-onec+twoc);
    Min=min(Min,three+four+cou+onec-twoc);
    return Min;
}
int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf(" %s",b[i]+1);
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(b[i][j]=='1')qs[i][j]=1;
            qs[i][j]+=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1];
        }
    }
    printf("%d\n",play(1,1,n,n));
    return 0;
}
/*
4
0001
0011
0111
1110
4
1111
1111
1111
1111
8
01010001
10100011
01010111
10101111
01010111
10100011
01010001
10100001
*/
