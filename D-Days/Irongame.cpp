/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[25];
int main()
{
    long long n,j,i;
    scanf("%lld",&n);
    dp[0]=1;
    for(i=1;i<=n;i++){
        for(j=0;j<i;j++){
            dp[i]+=((dp[j]%1000000000)*(dp[i-j-1]%1000000000))%1000000000;
        }
    }
    printf("%lld\n",dp[n]);
    return 0;
}
