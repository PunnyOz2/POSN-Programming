/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long dp[360];
int main()
{
    long long q,i,j,n,k;
    scanf("%lld",&q);
    dp[0]=1;
    //dp[1]=1;
    //dp[2]=3;
    dp[1]=1;
    dp[2]=3;
    dp[3]=12;
    for(i=4;i<=350;i++){
        for(j=0;j<i;j++){
            for(k=0;k<=j;k++){
                dp[i]+=((dp[k]%mod)*(dp[j-k]%mod))%mod*(dp[i-j-1]%mod);
                dp[i]%=mod;
            }
        }
    }
    while(q--){
        scanf("%lld",&n);
        printf("%lld\n",dp[n]);
    }
    return 0;
}
