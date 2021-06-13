/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct edge{
    long long u,w;
};
struct A{
    long long u,w,pot,last;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
vector<edge>g[80100];
priority_queue<A> q;
long long mark[80100],dis[10][80100];
int main()
{
    long long n,m,l,Q,i,u,v,w,last,j,cou;
    scanf("%lld %lld %lld %lld",&n,&m,&l,&Q);
    for(i=0;i<m;i++){
        scanf("%lld %lld %lld",&u,&v,&w);
        g[u].push_back({v,w});
    }
    for(i=1;i<=l;i++){
        scanf("%lld",&u);
        mark[u]=1;
    }
    for(i=1;i<=n;i++){
        for(j=0;j<=Q;j++){
            dis[j][i]=1e18;
        }
    }
    dis[0][1]=0;
    //node dis potioncou lastpot
    q.push({1,0,0,0});
    //if(mark[1]==1)q.push({1,0,1,1});
    while(!q.empty()){
        u=q.top().u;
        w=q.top().w;
        cou=q.top().pot;
        last=q.top().last;
        //printf("%lld %lld %lld %lld\n",u,w,cou,last);
        q.pop();
        if(mark[u] && cou<Q && last != u){
            last = u;
            cou++;
        }
        for(auto x:g[u]){
            if(dis[cou][x.u]>w+x.w/(1<<cou)){
                dis[cou][x.u]=w+x.w/(1<<cou);
                q.push({x.u,dis[cou][x.u],cou,last});
            }
        }
    }
    long long Min=1e18;
    for(i=0;i<=Q;i++){
        //printf("%lld\n",dis[i][n]);
        Min=min(Min,dis[i][n]);
    }
    printf("%lld\n",Min);
    return 0;
}
/*
9 9 1 1
1 2 256
2 3 256
3 4 256
4 9 256
1 5 256
5 6 256
6 7 256
7 8 256
8 9 256 5
*/
