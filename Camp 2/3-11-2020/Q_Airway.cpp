/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long u,w,mark;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
priority_queue<A> q;
vector<A> g[1010];
long long dis[2][1100];
int main()
{
    long long n,m,st,en,w,t,u,v,i,mark;
    scanf("%lld %lld %lld %lld",&n,&m,&st,&en);
    scanf("%lld %lld %lld %lld",&u,&v,&w,&t);
    g[u].push_back({v,w,t});
    for(i=1;i<=m;i++){
        scanf("%lld %lld %lld",&u,&v,&w);
        g[u].push_back({v,w,-1});
    }
    for(i=1;i<=n;i++){
        dis[0][i]=dis[1][i]=1e9;
    }
    dis[0][st]=0;
    q.push({st,0,0});
    while(!q.empty()){
        u=q.top().u;
        w=q.top().w;
        mark=q.top().mark;
        q.pop();
        for(auto x:g[u]){
            if(x.mark!=-1 && w<=x.mark && mark==0){
                dis[1][x.u]=dis[0][u]+x.w;
                q.push({x.u,dis[1][x.u],1});
            }
            else if(x.mark==-1 && dis[mark][x.u]>dis[mark][u]+x.w){
                dis[mark][x.u]=dis[mark][u]+x.w;
                q.push({x.u,dis[mark][x.u],mark});
            }
        }
    }
    printf("%lld\n",min(dis[0][en],dis[1][en]));
    return 0;
}
/*
4 4
0 3
1 3 -10 10
0 1 5
0 3 10
1 3 3
2 3 5
*/
