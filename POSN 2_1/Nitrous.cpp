/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,w,ni;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
vector<A> g[5010];
priority_queue<A> q;
int dp[5010][150];
int main()
{
	int n,m,k,i,u,v,w,j,ni;
	scanf("%d %d %d",&n,&m,&k);
	for(i=0;i<m;i++){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
	}
	for(i=0;i<=n;i++){
        for(j=0;j<=k;j++){
            dp[i][j]=1<<30;
        }
	}
	dp[1][0]=0;
	q.push({1,0,0});
    while(!q.empty()){
        u=q.top().v,w=q.top().w,ni=q.top().ni;
        q.pop();
        if(u==n && ni==0)break;
        for(auto x:g[u]){
            if(dp[x.v][ni]>dp[u][ni]+x.w)                     dp[x.v][ni]=dp[u][ni]+x.w    ,q.push({x.v,dp[x.v][ni],ni});
        }
        for(auto x:g[u]){
            if(ni+1<=k && dp[x.v][ni+1]>dp[u][ni]+x.w/2)    dp[x.v][ni+1]=dp[u][ni]+x.w/2 ,q.push({x.v, dp[x.v][ni+1],ni+1});
        }
    }
    int Min=1<<30;
    for(i=1;i<=k;i++){
        Min=min(Min,dp[n][i]);
    }
    printf("%d\n%d\n%d\n",dp[n][0],Min,dp[n][0]-Min);
    return 0;
}
/*
6 8 1
1 2 4
1 4 2
2 3 4
2 4 6
3 6 6
4 3 12
4 5 10
5 6 4
*/
