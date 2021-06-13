/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct B{
    long long u,w;
    bool operator<(const B&o)const{
        return w>o.w;
    }
};
struct C{
    long long u,w,st;
    bool operator<(const C&o)const{
        return w>o.w;
    }
};
priority_queue<C> q2;
priority_queue<B> q;
vector<B> g[50010];
long long dis[50010],sun[50010],dis2[2][50010];
int main()
{
    long long n,m,k,u,v,i,Max,w,id;
    scanf("%lld %lld %lld",&n,&m,&k);
    for(i=0;i<m;i++){
        scanf("%lld %lld %lld",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(i=1;i<=n;i++){
        dis[i]=dis2[0][i]=dis2[1][i]=1<<30;
    }
    long long cou=0,st;
    for(i=1;i<=k;i++){
        scanf("%lld %lld",&u,&v);
        sun[u]=max(sun[u],v);
    }
    dis[n]=0;
    q.push({n,0});
    while(!q.empty()){
        u=q.top().u;
        q.pop();
        for(auto x:g[u]){
            if(dis[x.u]>dis[u]+x.w)dis[x.u]=dis[u]+x.w,q.push({x.u,dis[x.u]});
        }
    }
    dis2[0][n]=0;
    q2.push({n,0,0});
    while(!q2.empty()){
        u=q2.top().u;
        st=q2.top().st;
        q2.pop();
        for(auto x:g[u]){
            if(st<1 && sun[x.u]!=0 && dis2[st+1][x.u]>dis2[st][u]+x.w-sun[x.u]) dis2[st+1][x.u]=dis2[st][u]+x.w-sun[x.u],q2.push({x.u,dis2[st+1][x.u],st+1});
            if(dis2[st][x.u]>dis2[st][u]+x.w)dis2[st][x.u]=dis2[st][u]+x.w,q2.push({x.u,dis2[st][x.u],st});
        }
    }
    long long temp=1<<30;
    for(i=1;i<n;i++){
        if(dis2[1][i]<=dis[i])printf("1\n");
        else printf("0\n");
    }
    return 0;
}
/*
4 5 1
1 2 20
2 3 5
2 4 3
1 4 10
3 4 2
2 5
*/
