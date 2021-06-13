/*
    TASK: Ant
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[100][100],room[100][100],r,c,cou,sum,b[10000];
void play(int i,int j){
    if(i<0||j<0||i>=r||i>=c) return;
    room[i][j]=cou;
    if(i-1>=0 && room[i-1][j]==0 && a[i][j]&2){
        sum++;play(i-1,j);
    }
    if(j-1>=0 && room[i][j-1]==0 && a[i][j]&1){
        sum++;play(i,j-1);
    }
    if(i+1<r && room[i+1][j]==0 && a[i][j]&8){
        sum++;play(i+1,j);
    }
    if(j+1<c && room[i][j+1]==0 && a[i][j]&4){
        sum++;play(i,j+1);
    }
}
int main()
{
    int i,j,Max=0,ansi,ansj;
    char ans;
    scanf("%d %d",&c,&r);
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&a[i][j]);
            a[i][j] = 15-a[i][j];
        }
    }
    cou=1;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(!room[i][j]){
                room[i][j]= cou;
                sum=1;
                play(i,j);
                b[cou]=sum;
                cou++;
            }
        }
    }
    for(j=0;j<c;j++){
        for(i=r-1;i>=0;i--){
            if(i-1>0 && room[i-1][j]!=room[i][j]){
                sum=b[room[i-1][j]]+b[room[i][j]];
                if(sum>Max)
                    Max=sum, ansj=j+1, ansi=i+1, ans='N';
            }
            if(j+1<c && room[i][j+1]!=room[i][j]){
                sum=b[room[i][j+1]]+b[room[i][j]];
                if(sum>Max)
                    Max=sum, ansj=j+1, ansi=i+1, ans='E';
            }


        }

    }
    printf("%d\n",Max);
    printf("%d %d %c",ansi,ansj,ans);
    return 0;
}
/*
7 4
11 6 11 6 3 10 6
7 9 6 13 5 15 5
1 10 12 7 13 7 5
13 11 10 8 10 12 13
*/
