/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dis[110][1100];
struct A{
    int u,w;
};
vector<A> g[1100];
struct B{
    int u,w,tank;
    bool operator<(const B&o)const{
        return w>o.w;
    }
};
int cost[1010];
priority_queue<B> q;
int main()
{
    int Q,n,m,i,u,v,w,tank,k,st,en,j,Min;
    scanf("%d",&Q);
    while(Q--){
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++){
            scanf("%d",&cost[i]);
        }
        for(i=1;i<=m;i++){
            scanf("%d %d %d",&u,&v,&w);
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }
        scanf("%d %d %d",&k,&st,&en);
        for(i=0;i<n;i++){
            for(j=0;j<=k;j++){
                dis[j][i]=1<<30;
            }
        }
        dis[0][st]=0;
        q.push({st,0,0});
        while(!q.empty()){
            u=q.top().u;
            w=q.top().w;
            tank=q.top().tank;
            q.pop();
            if(tank<k && dis[tank+1][u]>dis[tank][u]+cost[u]){
                dis[tank+1][u]=dis[tank][u]+cost[u];
                q.push({u,dis[tank+1][u],tank+1});
            }
            for(auto x:g[u]){
                if(tank-x.w>=0 && dis[tank-x.w][x.u]>dis[tank][u]){
                    dis[tank-x.w][x.u]=dis[tank][u];
                    q.push({x.u,dis[tank-x.w][x.u],tank-x.w});
                }
            }
        }
        Min=1<<30;
        for(i=0;i<=k;i++){
            Min=min(Min,dis[i][en]);
        }
        if(Min==1<<30)printf("-99\n");
        else printf("%d\n",Min);
        for(i=0;i<n;i++){
            g[i].clear();
        }
    }
    return 0;
}
/*
2
5 5
10 10 20 12 13
0 1 9
0 2 8
1 2 1
1 3 11
2 3 7
10 0 3
*/
