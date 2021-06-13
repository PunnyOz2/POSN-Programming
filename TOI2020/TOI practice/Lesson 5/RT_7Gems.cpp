#include<bits/stdc++.h>
using namespace std;
char a[210][210];
int gem[210][210];
int dis[210][210][(1<<7)+2][7];
struct A{
    int i,j,mark,tim;
};
queue<A> q;
int di[]={1,-1,0,0},dj[]={0,0,1,-1};
int main(){
    int n,m,i,j,cou=0,ni,nj,k,sti,stj,tim,mark,nmark,Min;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf(" %c",&a[i][j]);
            if(a[i][j]=='S'){
                sti=i,stj=j;
            }
            if(a[i][j]=='G'){
                cou++;
                gem[i][j]=cou;
            }
            for(k=0;k<=1<<7;k++)
                for(tim=1;tim<=6;tim++)dis[i][j][k][tim]=1<<30;
        }
    }
    dis[sti][stj][0][1]=1;
    q.push({sti,stj,0,1});
    while(!q.empty()){
        i=q.front().i;
        j=q.front().j;
        mark=q.front().mark;
        tim=q.front().tim;
        cou=__builtin_popcount(mark);
        q.pop();
        if(mark==((1<<7)-1)){
            printf("%d\n",tim-1);
            return 0;
        }
        if(((a[i][j]-'0')==((tim%6)+1) || (a[i][j]-'0')<=cou || a[i][j]=='.' || a[i][j]=='S' || a[i][j]=='G') && dis[i][j][mark][(tim%6)+1]>tim+1){
            dis[i][j][mark][(tim%6)+1]=tim+1;
            q.push({i,j,mark,tim+1});
        }
        for(k=0;k<4;k++){
            ni=i+di[k];
            nj=j+dj[k];
            nmark=mark;
            if(ni<1 || nj<1 || ni>n || nj>m)                     continue;
            if(a[ni][nj]=='#')                                   continue;
            if(a[ni][nj]=='G')                  nmark|=(1<<(gem[ni][nj]-1));
            if(((a[ni][nj]-'0')==((tim%6)+1) || (a[ni][nj]-'0')<=cou || a[ni][nj]=='.' || a[ni][nj]=='S' || a[ni][nj]=='G') && dis[ni][nj][nmark][(tim%6)+1]>tim+1){
                dis[ni][nj][nmark][(tim%6)+1]=tim+1;
                q.push({ni,nj,nmark,tim+1});
            }
        }
    }
    printf("-1\n");
    return 0;
}
/*
2 6
S##GGG
.6GGGG
2 7
S11GGGG
111#GGG
2 11
S456GGGGGGG
...........
1 9
SG1GGGGGG
*/
