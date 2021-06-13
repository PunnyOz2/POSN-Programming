/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int n;
int dp[1000100][2];
int a[1000100];
int play(int m,int state){
    if(dp[m][state]!=-1)return dp[m][state];
    if(m>n)return dp[m][state]=0;
    if(state==0){
        dp[m][state]=max(dp[m][state],a[m]+play(m+1,1));
        dp[m][state]=max(dp[m][state],a[m]+a[m+1]+play(m+2,1));
        dp[m][state]=max(dp[m][state],a[m]+a[m+1]+a[m+2]+play(m+3,1));
        return dp[m][state];
    }
    dp[m][state]=1<<30;
    dp[m][state]=min(dp[m][state],play(m+1,0));
    dp[m][state]=min(dp[m][state],play(m+2,0));
    dp[m][state]=min(dp[m][state],play(m+3,0));
    return dp[m][state];
}
int main()
{
    int i;
    scanf("%d",&n);
    memset(dp,-1,sizeof dp);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    printf("%d\n",play(1,0));
    return 0;
}
/*
10
9 0 0 10 1000 2 9 8 10 10

10
1 1 1 1 1 1 1 1 1 1
*/
