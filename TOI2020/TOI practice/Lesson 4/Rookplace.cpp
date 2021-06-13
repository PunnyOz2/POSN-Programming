#include<bits/stdc++.h>
using namespace std;
long long dp[100100];
int main(){
    long long i,n;
    scanf("%lld",&n);
    dp[2]=1;
    dp[3]=2;
    for(i=4;i<=n;i++){
        dp[i]=((dp[i-1]+dp[i-2])%1000000007)*(i-1);
        dp[i]%=1000000007;
    }
    printf("%lld\n",dp[n]);
    return 0;
}
/*
3 4
*/
