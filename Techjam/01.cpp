#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long n,m,a[2200],b[2200],dp[2200][2200],qsa[2200],qsb[2200];
long long play(long long i,long long j){
    if(dp[i][j]!=-1)return dp[i][j];
    if(qsa[i]+qsb[j]<0)return 0;
    if(i==0 && j==0)return 1;
    if(i==0)return dp[i][j]=play(i,j-1)%MOD;
    if(j==0)return dp[i][j]=play(i-1,j)%MOD;
    return dp[i][j]=(play(i,j-1)%MOD+play(i-1,j)%MOD)%MOD;
}
int main()
{
    long long i,j;
    scanf("%lld",&n);
    memset(dp,-1,sizeof dp);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        qsa[i]+=qsa[i-1]+a[i];
    }
    scanf("%lld",&m);
    for(j=1;j<=m;j++){
        scanf("%lld",&b[j]);
        qsb[j]+=qsb[j-1]+b[j];
    }
    printf("%lld",play(n,m));
    return 0;
}
