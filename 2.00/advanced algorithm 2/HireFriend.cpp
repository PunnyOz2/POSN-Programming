/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int dp[110][10010];
int main()
{
	int n,d,i,j;
	scanf("%d %d",&n,&d);
	dp[1][0]=1;
	for(j=1;j<=n;j++)
        dp[1][j]=1;
    for(i=2;i<d;i++){
        dp[i][0]=dp[i][j-1]+dp[i-1][j];
        for(j=1;j<=d;j++){
            dp[i][j]=dp[i][j-1]+dp[i-1][j];
            if(j-i>=0)dp[i][j]-=dp[i-1][j-i];
            dp[i][j]%=mod,dp[i][j]+=mod;dp[i][j]%=mod;
        }
    }
    printf("%d\n",(dp[n][d]-dp[n][d-1]+mod)%mod);
    return 0;
}
/*
3
1 5
4 8
3 11
*/
