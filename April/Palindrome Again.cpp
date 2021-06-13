/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dp[5100][5100];
char a[5100];
int main()
{
	int n,i,j,Max=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf(" %c",&a[i]);
	for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(a[i]==a[n-j+1])dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
	}
	printf("%d\n",n-dp[n][n]);
    return 0;
}
/*
5
Ab3bd
*/
