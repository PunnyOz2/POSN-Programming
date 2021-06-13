/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long dis[20100],dis2[20100];
struct A{
    long long u,w;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
priority_queue<A> q;
vector<A> g[20100];
int main()
{
    long long n,m,st,en,t,i,u,v,w;
    scanf("%lld %lld",&n,&m);
    scanf("%lld %lld %lld",&st,&en,&t);
    for(i=0;i<m;i++){
        scanf("%lld %lld %lld",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(i=0;i<n;i++){
        dis[i]=1<<30;
        dis2[i]=1<<30;
    }
    dis[st]=0;
    q.push({st,0});
    while(!q.empty()){
        u=q.top().u;
        w=q.top().w;
        //printf("%d ",u);
        q.pop();
        for(auto x:g[u]){
            //printf("%d %d  ",x.u,dis[x.u]);
            if(dis[x.u]>dis[u]+x.w)dis[x.u]=dis[u]+x.w,q.push({x.u,dis[x.u]});
        }
    }
    dis2[en]=0;
    q.push({en,0});
    while(!q.empty()){
        u=q.top().u;
        w=q.top().w;
        q.pop();
        for(auto x:g[u]){
            if(dis2[x.u]>dis2[u]+x.w)dis2[x.u]=dis2[u]+x.w,q.push({x.u,dis2[x.u]});
        }
    }
    for(i=0;i<n;i++){
        //printf("%d %d %d\n",i,dis[i],dis2[i]);
        if(dis[i]+dis2[i]>t)printf("%lld ",i);
    }
    return 0;
}
/*
5 6
0 4 17
0 1 6
1 2 5
3 2 8
2 4 8
0 3 5
4 1 9
*/
