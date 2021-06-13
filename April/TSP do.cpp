/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int qs[2500];
int dis[2500][2500];
int dp[1800][1800];
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&dis[i][j]);
    for(i=2;i<=n;i++){
        qs[i]=qs[i-1]+dis[i-1][i];
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)dp[i][j]=1<<29;
    dp[1][1]=0;
    dp[1][2]=dis[1][2];
    for(i=2;i<=n;i++){
        for(j=1;j<i;j++)
            dp[i][j]=min(dp[i][j],dp[i-1][j]+dis[i][i-1]);
        for(j=1;j<=i-2;j++)
            dp[i][i-1]=min(dp[i][i-1],dp[j][j+1]+dis[i][j]+qs[i-1]-qs[j+1]);
        for(j=1;j<i;j++)
            dp[i][i+1]=min(dp[i][i+1],dp[i][j]+dis[j][i+1]);
    }
    int ans=1<<29;
    for(i=1;i<n;i++)
        ans=min(ans,dp[i][i+1]+qs[n]-qs[i+1]);
    for(i=1;i<n;i++)
        ans=min(ans,dp[n][i]);
    printf("%d\n",ans);
    return 0;
}
/*
3
0 6 2
6 0 4
2 4 0
*/
