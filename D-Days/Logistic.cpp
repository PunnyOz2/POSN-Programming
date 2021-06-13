/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long cost[120];
long long dis[120][120][3];
struct A{
    long long u,w,tank,state;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
vector<A> g[120];
priority_queue<A> q;
int main()
{
    long long n,i,u,v,w,m,st,en,t,j,tank,state;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&cost[i]);
    }
    scanf("%lld %lld %lld",&st,&en,&t);
    scanf("%lld",&m);
    for(i=0;i<m;i++){
        scanf("%lld %lld %lld",&u,&v,&w);
        g[u].push_back({v,w,0,0});
        g[v].push_back({u,w,0,0});
    }
    for(i=1;i<=n;i++){
        for(j=0;j<=100;j++){
            dis[i][j][0]=dis[i][j][1]=1<<30;
        }
    }
    dis[st][0][0]=0;
    q.push({st,0,0,0});
    while(!q.empty()){
        u=q.top().u;
        w=q.top().w;
        tank=q.top().tank;
        state=q.top().state;
        q.pop();
        if(tank<t && dis[u][tank+1][state]>dis[u][tank][state]+cost[u]){
            dis[u][tank+1][state]=dis[u][tank][state]+cost[u];
            q.push({u,dis[u][tank+1][state],tank+1,state});
        }
        if(tank<t && state<1){
            if(dis[u][t][state+1]>dis[u][tank][state]){
                dis[u][t][state+1]=dis[u][tank][state];
                q.push({u,dis[u][t][state+1],t,state+1});
            }
        }
        for(auto x:g[u]){
            if(tank-x.w>=0 && dis[x.u][tank-x.w][state]>dis[u][tank][state]){
                dis[x.u][tank-x.w][state]=dis[u][tank][state];
                q.push({x.u,dis[x.u][tank-x.w][state],tank-x.w,state});
            }
    }
    }
    long long Min=1<<30;
    printf("%lld\n",dis[en][t][1]);
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
