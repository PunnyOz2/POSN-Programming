/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long best(long long n,long long k){
    k++;
    return k*(n/k)*(n/k+1)/2+(n%k)*(n/k+1);
}
long long dp[107][505],cnt[107];
int main()
{
    long long n,q,k,i,m,j,K,num;
    scanf("%lld %lld %lld",&n,&m,&k);
    for(i=1;i<=n;i++)scanf("%lld",&num),cnt[num]++;
    for(i=1;i<=m;i++){
        for(j=0;j<=k;j++){
            dp[i][j]=1e18;
            for(K=0;K<=j;K++){
                dp[i][j]=min(dp[i][j],best(cnt[i],K)+dp[i-1][j-K]);
            }
        }
    }
    printf("%lld\n",dp[m][k]);
    return 0;
}
/*
5
1
2
1 1 1 1 1
*/
