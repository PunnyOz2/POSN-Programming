/*
    TASK: Plantation
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,w,k;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
int dis[5010][105];
vector<A> g[5010];
priority_queue<A> dijk;
int main()
{
    int n,m,k,s,e,w,i,j,v,nk,mi=1<<30;
    scanf("%d %d %d",&n,&m,&k);
    while(m--){
        scanf("%d %d %d",&s,&e,&w);
        g[s].push_back({e,w,0}),g[e].push_back({s,w,0});
    }
    for(i=1;i<=n;i++)
        for(j=0;j<=k;j++)
            dis[i][j]=1<<30;
    dijk.push({1,0,0});
    dis[1][0]=0;
    while(!dijk.empty()){
        v=dijk.top().v,w=dijk.top().w,nk=dijk.top().k;
        dijk.pop();
        if(v==n &&nk==0) break;
        for(auto x:g[v]){
            if(nk<k && dis[v][nk]+x.w/2<dis[x.v][nk+1]){
                dis[x.v][nk+1]=dis[v][nk]+x.w/2;
                dijk.push({x.v,dis[x.v][nk+1],nk+1});
            }
            if(dis[v][nk]+x.w<dis[x.v][nk]){
                dis[x.v][nk]=dis[v][nk]+x.w;
                dijk.push({x.v,dis[x.v][nk],nk});
            }
        }
    }
    printf("%d\n",dis[n][0]);
    for(i=1;i<=k;i++)
        mi=min(mi,dis[n][i]);
    printf("%d\n%d\n",mi,dis[n][0]-mi);

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
