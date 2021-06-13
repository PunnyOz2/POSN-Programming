/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],dp[5010][110];
long long play(long long now,long long k){
    if(now>n||k==0)return 0;
    if(dp[now][k]!=-1)return dp[now][k];
    long long Max=0,i;
//    Max=max(Max,play(now*2,k));
//    Max=max(Max,play(now*2+1,k));
    for(i=0;i<=k-1;i++){
        Max=max(Max,play(now*2,i)+play(now*2+1,k-i-1)+a[now]);
    }
    return dp[now][k]=Max;
}
int main()
{
    long long k,i,ans=0;
    scanf("%lld %lld",&n,&k);
    memset(dp,-1,sizeof dp);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(i=1;i<=n;i++)ans=max(ans,play(i,k));
    printf("%lld",ans);
    return 0;
}
/*

*/
