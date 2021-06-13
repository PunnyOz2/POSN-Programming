/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char s[300];
int dp[260][260][4];
int main()
{
	int i,n,ii,m,j;
	for(ii=0;ii<20;ii++){
        scanf("%d",&n);
        scanf(" %s",s);
        for(i=0;i<n;i++){
            dp[i][i][s[i]-'0']=1;
        }
        for(m=1;m<=n;m++){
            for(i=0;i<=n-m;i++){
                for(j=i;j<i+m-1;j++){
                    if(dp[i][j][0] && dp[j+1][i+m-1][0])dp[i][i+m-1][2]=1;
                    if(dp[i][j][0] && dp[j+1][i+m-1][1])dp[i][i+m-1][1]=1;
                    if(dp[i][j][0] && dp[j+1][i+m-1][2])dp[i][i+m-1][0]=1;
                    if(dp[i][j][1] && dp[j+1][i+m-1][0])dp[i][i+m-1][2]=1;
                    if(dp[i][j][1] && dp[j+1][i+m-1][1])dp[i][i+m-1][1]=1;
                    if(dp[i][j][1] && dp[j+1][i+m-1][2])dp[i][i+m-1][1]=1;
                    if(dp[i][j][2] && dp[j+1][i+m-1][0])dp[i][i+m-1][1]=1;
                    if(dp[i][j][2] && dp[j+1][i+m-1][1])dp[i][i+m-1][2]=1;
                    if(dp[i][j][2] && dp[j+1][i+m-1][2])dp[i][i+m-1][1]=1;
                }
            }
        }
        if(dp[0][n-1][0])printf("yes\n");
        else printf("no\n");
        memset(dp,0,sizeof dp);
    }
    return 0;
}
