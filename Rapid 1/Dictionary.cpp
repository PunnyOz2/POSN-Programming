#include<bits/stdc++.h>
using namespace std;
long long a[310],dp[310][310];
long long play(long long l,long long r){
    if(l>r) return 0;
    if(dp[l][r]!=-1)return dp[l][r];
    long long mi=1e18;
    for(long long k=l;k<=r;k++)
        mi=min(mi,play(l,k-1)+play(k+1,r)+a[r]-a[l-1]);
    return dp[l][r]=mi;
}
int main()
{
    long long sum,i,n,j;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)scanf("%lld",&a[i]),a[i]+=a[i-1];
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)dp[i][j]=-1;
    printf("%lld\n",play(1,n));
    return 0;
}
/*
5
10 5 17 2 6
    7
    77 6 13 79 20 11 8
*/
