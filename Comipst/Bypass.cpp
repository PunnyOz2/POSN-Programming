/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[5][200000],ans[200000];
vector<long long> g[100100];
long long n,i,u,v,old;
void ro(long long u,long long old){
    dp[0][u]=1;
    for(auto x:g[u]){
        if(x==old)continue;
        ro(x,u);
        ans[u]=max(ans[u],max(dp[2][u]*dp[0][x],dp[1][u]*dp[1][x]));
        ans[u]=max(ans[u],ans[x]);
        dp[0][u]+=dp[0][x];
        dp[1][u]=max(dp[1][u],dp[0][x]);
        dp[2][u]=max(dp[2][u],dp[1][x]);
        dp[3][u]=max(dp[3][u],dp[2][x]);
        ans[u]=max(ans[u],(n-dp[0][x])*dp[2][x]);
    }
}
int main()
{
    scanf("%lld",&n);
    for(i=1;i<n;i++){
        scanf("%lld %lld",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ro(1,0);
    printf("%lld\n",ans[1]);
    return 0;
}
/*
6
1 3
2 3
3 4
4 5
5 6
*/
