/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[1000100];
int main()
{
    long long n,k,i,j,pi,wi;
    scanf("%lld %lld",&n,&k);
    for(i=1;i<=k;i++){
        dp[i]=1<<30;
    }
    dp[0]=0;
    for(i=1;i<=n;i++){
        scanf("%lld",&pi);
        for(j=pi;j<=k;j++){
            dp[j]=min(dp[j],dp[j-pi]+1);
        }
    }
    if(dp[k]==1<<30)printf("0\n");
    else printf("%lld\n",dp[k]);
    return 0;
}
/*
3 10
2 3 4
*/
