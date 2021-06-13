/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dp[102][102][102][102];
int n,m,i,j;
int play(int a,int b,int c,int d){
    if(a>n || b>m || c>i || d>j)return 0;
    if(dp[a][b][c][d]!=-1)return dp[a][b][c][d];
    if(a==n && b==m)return 1;
    //printf("%d %d %d %d\n",a,b,c,d);
    int sum=0;
    sum+=play(a+1,b,c+1,0)%1000000007;
    sum+=play(a,b+1,0,d+1)%1000000007;
    return dp[a][b][c][d]=sum%1000000007;
}
int main()
{
    scanf("%d %d %d %d",&n,&m,&i,&j);
    memset(dp,-1,sizeof dp);
    printf("%d\n",play(0,0,0,0));
    return 0;
}
