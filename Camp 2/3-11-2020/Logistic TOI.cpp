/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dis[110][1100][2];
struct A{
    int u,w;
};
vector<A> g[1100];
struct B{
    int u,w,tank,mark;
    bool operator<(const B&o)const{
        return w>o.w;
    }
};
int cost[1010];
priority_queue<B> q;
int main()
{
    int Q,n,m,i,u,v,w,tank,k,st,en,j,Min,mark;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&cost[i]);
    }
    scanf("%d %d %d",&st,&en,&k);
    scanf("%d",&m);
    for(i=1;i<=m;i++){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(i=1;i<=n;i++){
        for(j=0;j<=k;j++){
            dis[j][i][1]=dis[j][i][0]=1<<30;
        }
    }
    dis[0][st][0]=0;
    q.push({st,0,0,0});
    while(!q.empty()){
        u=q.top().u;
        w=q.top().w;
        tank=q.top().tank;
        mark=q.top().mark;
        //printf("%d %d %d %d\n",u,w,tank,mark);
        q.pop();
        if(tank<k && dis[tank+1][u][mark]>dis[tank][u][mark]+cost[u]){
            //printf("HI %d %d %d %d\n",u,dis[tank+1][u][mark],tank+1,);
            dis[tank+1][u][mark]=dis[tank][u][mark]+cost[u];
            q.push({u,dis[tank+1][u][mark],tank+1,mark});
        }
        if(mark==0 && tank<k && dis[k][u][1]>dis[tank][u][0]){
            dis[k][u][1]=dis[tank][u][0];
            q.push({u,dis[k][u][1],k,1});
        }
        for(auto x:g[u]){
            if(tank-x.w>=0 && dis[tank-x.w][x.u][mark]>dis[tank][u][mark]){
                dis[tank-x.w][x.u][mark]=dis[tank][u][mark];
                q.push({x.u,dis[tank-x.w][x.u][mark],tank-x.w,mark});
            }
        }
    }
    printf("%d\n",min(dis[k][en][1],dis[k][en][0]));
    return 0;
}
/*
4
7 1 8 10
1 4 100
5
1 2 60
1 3 50
1 4 90
2 4 30
3 4 20
*/
