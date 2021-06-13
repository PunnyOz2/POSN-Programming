/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long u,w,st;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
priority_queue<A> q;
struct B{
    long long u,w;
};
vector<B> g[100100];
long long dis[3][100100];
int main()
{
    long long n,m,k,t,i,u,v,w,st;
    scanf("%lld %lld %lld %lld",&n,&m,&k,&t);
    for(i=1;i<=m;i++){
        scanf("%lld %lld %lld",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(i=1;i<=n;i++)dis[0][i]=dis[1][i]=1<<30;
    dis[0][1]=0;
    q.push({1,0,0});
    while(!q.empty()){
        u=q.top().u;
        w=q.top().w;
        st=q.top().st;
        q.pop();
        for(auto x:g[u]){
            if(dis[st][x.u]>dis[st][u]+x.w){
                dis[st][x.u]=dis[st][u]+x.w;
                q.push({x.u,dis[st][x.u],st});
            }
            if(st==0 && dis[1][x.u]>dis[0][u]+k){
                dis[1][x.u]=dis[0][u]+k;
                q.push({x.u,dis[1][x.u],1});
            }
        }
    }
    if(min(dis[0][n],dis[1][n])<=t)printf("Happy Winnie the Pooh :3\n%lld\n",min(dis[0][n],dis[1][n]));
    else printf("No Honey TT\n");
    return 0;
}
/*
4 5 3 2
1 2 2
2 3 3
1 3 5
1 4 4
3 4 3
*/
