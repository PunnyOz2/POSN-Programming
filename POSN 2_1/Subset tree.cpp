/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100100],dp[100005][3],n,mark[100100];
vector<int> g[100100];
void dfs(long long u){
    if(mark[u]) return;
    mark[u]=1;
    dp[u][1]=a[u];
    for(auto x:g[u]){
        if(mark[x])continue;
        dfs(x);
        dp[u][1]+=dp[x][0];
        dp[u][0]+=max(dp[x][0],dp[x][1]);
    }
}
int main()
{   int q,n,i,u,v;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        for(i=1;i<n;i++){
            scanf("%d %d",&u,&v);
            g[u].push_back(v),g[v].push_back(u);
        }
        dfs(1);
        printf("%lld\n",max(dp[1][0],dp[1][1]));
        memset(dp,0,sizeof dp);
        memset(mark,0,sizeof mark);
        for(i=1;i<=n;i++)
            g[i].clear();
    }
    return 0;
}
