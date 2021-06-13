/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long u,w;
    bool operator <(const A&o)const{
        return w>o.w;
    }
};
priority_queue<A> q;
vector<A> g[100100];
long long dis[100100],dis2[100100];
long long ans[100100];
int main()
{
    long long n,m,i,u,v,w,st,en,en2;
    scanf("%lld %lld",&n,&m);
    for(i=0;i<m;i++){
        scanf("%lld %lld %lld",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    scanf("%lld %lld",&st,&en);
    q.push({st,0});
    for(i=1;i<=n;i++)dis[i]=dis2[i]=ans[i]=1e18;
    dis[st]=0;
    while(!q.empty()){
        u=q.top().u;
        w=q.top().w;
        q.pop();
        for(auto x:g[u]){
            if(dis[x.u]>dis[u]+x.w)dis[x.u]=dis[u]+x.w,q.push({x.u,dis[x.u]});
        }
    }
    q.push({en,0});
    dis2[en]=0;
    while(!q.empty()){
        u=q.top().u;
        w=q.top().w;
        q.pop();
        for(auto x:g[u]){
            if(dis2[x.u]>dis2[u]+x.w)dis2[x.u]=dis2[u]+x.w,q.push({x.u,dis2[x.u]});
        }
    }
    scanf("%lld %lld",&st,&en2);
    q.push({st,0});
    ans[st]=0;
    while(!q.empty()){
        u=q.top().u;
        w=q.top().w;
        q.pop();
        if(u==en2){printf("%lld\n",w);return 0;}
        for(auto x:g[u]){
            if(dis[x.u]+dis2[x.u]>dis[en] && ans[x.u]>ans[u]+x.w)ans[x.u]=ans[u]+x.w,q.push({x.u,ans[x.u]});
        }
    }
    printf("-1\n");
    return 0;
}
/*
8 13

1 2 1
2 3 3
2 6 2
3 6 1
3 4 4
4 6 5
4 5 1
1 7 5
7 5 6
1 8 7
5 8 8
6 8 1
7 3 1

2 4
7 8
*/
