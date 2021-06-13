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
};
vector<A> g[10100];
int dis[10100];
queue<A>q;
struct B{
    int u,w;
    bool operator<(const B&o)const{
        return w>o.w;
    }
};
priority_queue<B> q2;
int main()
{
    int n,m,st,en,k,i,u,v,w;
    scanf("%d %d",&n,&m);
    scanf("%d %d %d",&st,&en,&k);
    for(i=0;i<m;i++){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    q.push({st,0});
    for(i=0;i<=n;i++)dis[i]=1<<30;
    dis[st]=0;
    while(!q.empty()){
        u=q.front().u;
        q.pop();
        for(auto x:g[u]){
            if(dis[x.u]>dis[u]+x.w)dis[x.u]=dis[u]+x.w,q.push({x.u,dis[x.u]});
        }
    }
    q2.push({en,0});
    while(!q2.empty()){
        u=q2.top().u;
        w=q2.top().w;
        q2.pop();
        if(dis[u]<=k){
            printf("%d %d %d",u,dis[u],w);
            break;
        }
        for(auto x:g[u]){
            if(dis[x.u]<dis[u])q2.push({x.u,w+x.w});
        }
    }
    return 0;
}
/*
8 11
0 5 45
0 1 10
0 2 10
1 3 10
1 5 70
2 3 10
2 4 30
2 6 10
3 5 30
4 5 20
6 7 15
7 5 20
*/
