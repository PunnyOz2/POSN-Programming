/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long a[50100],pascal[50010][1010];
long long dp[105][1005];
map<long long,long long> mp;
int main()
{
    long long n,m,i,j,l,k,run;
    scanf("%lld %lld",&n,&k);
    pascal[0][0]=1;
    for(i=1;i<=n;i++){
        pascal[i][0]=1;
        for(j=1;j<=min(i,1000ll);j++){
            pascal[i][j]=(pascal[i-1][j]%1000000007+pascal[i-1][j-1]%1000000007)%1000000007;
        }
    }
    for(i=0;i<n;i++){
        scanf("%lld",&a[i]);
        mp[a[i]]++;
    }
    run=0;
    dp[0][0]=1;
    long long cntpeo=0;
    long long peo;
    for(auto x:mp){
        run++;
        long long peo=x.second;
        for(j=0;j<=k;j++){
            for(l=0;l<=peo;l++){
                if(l>j)break;
                if(!cntpeo&&j) break;
                long long star=l,bar=max(0ll,cntpeo-1);
                dp[run][j]+=dp[run-1][j-l]*pascal[bar+star][min(bar,star)];
                dp[run][j]%=1000000007;
            }
        }
        cntpeo+=peo;
    }
    printf("%lld\n",dp[run][k]);
    return 0;
}
/*
3 1
1 2 3
*/
