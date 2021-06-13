/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[100100];
int main()
{
	int n,i;
	scanf("%d",&n);
	dp[2]=1;
	for(i=2;i<=n;i++){
        if(i%2==0)
            dp[i+1]=((i+1)*dp[i]-1)%1000000007;
        else
            dp[i+1]=((i+1)*dp[i]+1)%1000000007;
	}
	printf("%lld\n",dp[n]);
    return 0;
}
