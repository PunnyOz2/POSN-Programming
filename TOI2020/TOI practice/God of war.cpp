/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,w;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
priority_queue<A> q;
vector<A>g[100100];
int dis[100100],dis2[100100];
int ans[200100];
queue<pair<int,int>>gg;
int main(){
    int n,m,i,u,v,w,temp,st,en,state,sum=0,Max;
    scanf("%d %d",&n,&m);
    scanf("%d %d",&st,&en);
    for(i=1;i<=m;i++){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        gg.push({u,v});
        sum+=w;
    }
    for(i=0;i<n;i++)dis[i]=dis2[i]=1<<30;
    dis[st]=0;
    q.push({st,0});
    while(!q.empty()){
        u=q.top().u;
        w=q.top().w;
        q.pop();
        for(auto x:g[u]){
            if(dis[x.u]>dis[u]+x.w){
                dis[x.u]=dis[u]+x.w;
                q.push({x.u,dis[x.u]});
            }
        }
    }
    dis2[en]=0;
    q.push({en,0});
    while(!q.empty()){
        u=q.top().u;
        w=q.top().w;
        q.pop();
        for(auto x:g[u]){
            if(dis2[x.u]>dis2[u]+x.w){
                dis2[x.u]=dis2[u]+x.w;
                q.push({x.u,dis2[x.u]});
            }
        }
    }
    Max=-1<<30;
    while(!gg.empty()){
        u=gg.front().first;
        v=gg.front().second;
        gg.pop();
        Max=max(Max,sum-dis[u]-dis2[v]);
        Max=max(Max,sum-dis2[u]-dis[v]);
    }
    printf("%d\n",Max);
    return 0;
}
/*
4 4
0 3
0 1 2
1 3 2
0 2 4
2 3 5
*/
