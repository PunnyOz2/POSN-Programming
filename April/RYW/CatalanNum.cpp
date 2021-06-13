/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1010];
int main()
{
    int q,n,i,j;
	dp[0]=dp[1]=1;
	for(i=2;i<=1000;i++){
        for(j=0;j<i;j++){
            dp[i]+=(dp[j]%9973)*(dp[i-j-1]%9973);
            dp[i]%=9973;
        }
	}
	scanf("%d",&q);
	while(q--){
        scanf("%d",&n);
        printf("%d\n",dp[n-1]);
	}
    return 0;
}
