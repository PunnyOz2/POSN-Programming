/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long qs[100100],dp[100100];
int main()
{
    long long n,k,i;
    scanf("%lld %lld",&n,&k);
    dp[1]=1;
    dp[2]=2;
    qs[1]=1;
    qs[2]=3;
    for(i=3;i<=k;i++){
        dp[i]=(qs[i-1]+1)%2009;
        qs[i]=(qs[i-1]+dp[i])%2009;
        //printf("%d ",dp[i]);
    }
    for(i=k+1;i<=n;i++){
        dp[i]=(qs[i-1]-qs[i-k-1]+2009)%2009;
        qs[i]=(qs[i-1]+dp[i])%2009;
        //printf("%d %d %d\n",i,dp[i],qs[i]);
    }
    printf("%lld\n",dp[n]);
    return 0;
}
/*

*/
