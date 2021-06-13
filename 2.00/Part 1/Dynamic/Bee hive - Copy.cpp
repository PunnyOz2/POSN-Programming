/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1100][1100],n,m,i,j,cou=0,Max=-1000000,w,jj;;
void play(int i,int j,int w){
    if(i==n && w>Max){
            cou=1,Max=max(w,Max);
            return;
    }
    if(i==n&&w==Max){cou++;return;}
    if(i==n&&w<Max)return;
    if(i%2==1){
            if(dp[i+1][j-1]>dp[i+1][j])
                play(i+1,j-1,w+dp[i+1][j-1]);
            else if(dp[i+1][j-1]<dp[i+1][j])
                play(i+1,j,w+dp[i+1][j]);
            else{
                play(i+1,j,w+dp[i+1][j]);
                if(j-1>=1)play(i+1,j-1,w+dp[i+1][j-1]);
            }
        }
        else if(i%2==0){
            if(dp[i+1][j+1]>dp[i+1][j])
                play(i+1,j+1,w+dp[i+1][j+1]);
            else if(dp[i+1][j+1]<dp[i+1][j])
                play(i+1,j,w+dp[i+1][j]);
            else{
                play(i+1,j,w+dp[i+1][j]);
                if(j+1<=m)play(i+1,j+1,w+dp[i+1][j+1]);
            }
        }
}
int main()
{
    scanf("%d %d",&n,&m);
    for(i=n;i>=1;i--){
        for(j=1;j<=m;j++){
            scanf("%d",&dp[i][j]);
        }
    }
    cou=0;
    for(j=1;j<=m;j++)
        play(1,j,dp[1][j]);
    printf("%d %d",Max,cou);
    return 0;
}
/*
7 5
10 8 25 13 16
4 23 12 1 14
14 17 0 11 26
6 3 3 8 10
4 5 16 5 14
8 4 4 1 7
8 3 1 4 5

5 5
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
2 1 2 1 2
1 2 1 2 1
*/
