/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dp[2000][1010];
int main()
{
	int q,i,j,n,m;
	scanf("%d",&q);
	dp[0][0]=1;
	for(i=1;i<=1000;i++){
        for(j=1;j<=1000;j++){
            dp[i][j]=(dp[i-1][j]*j)%9871+(dp[i-1][j-1])%9871;
            dp[i][j]%=9871;
        }
	}
	while(q--){
        scanf("%d %d",&n,&m);
        printf("%d\n",dp[n][m]);
	}
    return 0;
}
