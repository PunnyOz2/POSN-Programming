/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dp[2010][310];
struct A{
    int u,v,hap,w;
};
vector<A> g;
int main()
{
    int n,m,k,st,en,i,j,hap,v,u,w;
    scanf("%d %d %d %d %d",&n,&m,&k,&st,&en);
    for(i=1;i<=n;i++){
        for(j=0;j<=k;j++)dp[j][i]=-1e9;
    }
    for(i=1;i<=m;i++){
        scanf("%d %d %d %d",&u,&v,&hap,&w);
        g.push_back({u,v,hap,w});
    }
    dp[0][st]=0;
    for(i=1;i<=k;i++){
        for(j=0;j<m;j++){
            if(i<g[j].w)continue;
            dp[i][g[j].u]=max(dp[i][g[j].u],dp[i-g[j].w][g[j].v]+g[j].hap);
            dp[i][g[j].v]=max(dp[i][g[j].v],dp[i-g[j].w][g[j].u]+g[j].hap);
        }
    }
    int Max=-1e9;
    for(i=0;i<=k;i++){
        Max=max(Max,dp[i][en]);
    }
    if(Max<0)printf("Impossible");
    else printf("%d\n",Max);
    return 0;
}
/*
5 4 15
1 5
1 3 1 2
2 3 4 2
4 3 4 2
5 3 1 2
*/
