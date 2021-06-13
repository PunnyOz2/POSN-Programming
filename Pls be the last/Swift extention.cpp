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
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
struct B{
    long long u,v,w;
};
B a[5010];
priority_queue<A> q;
vector<A> g[110];
long long dis[110];
int main()
{
    long long n,m,i,u,v,w,j,ans,Max,unow,vnow,wnow;
    scanf("%lld %lld",&n,&m);
    for(i=0;i<m;i++){
        scanf("%lld %lld %lld",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        a[i]={u,v,w};
    }
    for(j=1;j<=n;j++)dis[j]=1<<30;
    dis[1]=0;
    q.push({1,0});
    while(!q.empty()){
        u=q.top().u;
        w=q.top().w;
        q.pop();
        if(u==n){
            ans=w;break;
        }
        for(auto x:g[u]){
            if(dis[x.u]>w+x.w)dis[x.u]=w+x.w,q.push({x.u,dis[x.u]});
        }
    }
    while(!q.empty())q.pop();
    Max=-1;
    for(i=0;i<m;i++){
        unow=a[i].u;
        vnow=a[i].v;
        wnow=a[i].w;
        for(j=1;j<=n;j++)dis[j]=1<<30;
        dis[1]=0;
        q.push({1,0});
        while(!q.empty()){
            u=q.top().u;
            w=q.top().w;
            q.pop();
            if(u==n){
                Max=max(Max,dis[n]);break;
            }
            for(auto x:g[u]){
                if((u==unow && x.u==vnow)||(u==vnow && x.u==unow)){
                    if(dis[x.u]>w+x.w*2)dis[x.u]=w+x.w*2,q.push({x.u,dis[x.u]});
                }
                else if(dis[x.u]>w+x.w)dis[x.u]=w+x.w,q.push({x.u,dis[x.u]});
            }
        }
        while(!q.empty())q.pop();
    }
    printf("%lld\n",Max-ans);
    return 0;
}
/*
5 7
1 2 5
1 3 1
2 3 8
2 4 7
3 5 7
3 4 3
4 5 2
*/
