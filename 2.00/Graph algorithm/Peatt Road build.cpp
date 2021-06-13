/*
    TASK: Plantation
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,w,cnt;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
int dis[2][1010];
vector<A> g[1010];
priority_queue<A>dijk;
int main()
{
    int n,m,i,s,e,w,u,ans,l,r,mid;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d %d %d",&s,&e,&w);
        g[s].push_back({e,w,i}),g[e].push_back({s,w,i});
    }
    for(i=0;i<=n;i++)dis[0][i]=dis[1][i]=1<<30;
    dis[0][1]=0;
    dijk.push({1,0,0});
    while(!dijk.empty()){
        u=dijk.top().v, w=dijk.top().w, i=dijk.top().cnt;
        dijk.pop();
        for(auto x:g[u]){
            if(w+x.w<dis[i%2][x.v]){
                dis[i%2][x.v]=w+x.w;
                dijk.push({x.v,dis[i%2][x.v],i+1});
            }
        }
    }
    ans=dis[0][n];
    l=1,r=m;
    while(l<r){
        mid=(l+r)/2;
        for(i=0;i<=n;i++) dis[0][i]=dis[1][i]=1<<30;
        dis[0][1]=0;
        dijk.push({1,0,0});
        while(!dijk.empty()){
            u=dijk.top().v, w=dijk.top().w, i=dijk.top().cnt;
            dijk.pop();
            for(auto x:g[u]){
                if(w+x.w<dis[i%2][x.v] && x.cnt<=mid){
                    dis[i%2][x.v]=w+x.w;
                    dijk.push({x.v,dis[i%2][x.v],i+1});
                }
            }
        }
            if(dis[0][n]==ans)      r=mid;
            else                    l=mid+1;
    }
    printf("%d %d\n",l,ans);

    return 0;
}
/*
5 10
4 5 7
3 2 1
3 5 5
5 2 5
1 4 6
2 1 1
4 3 7
1 3 7
4 2 4
1 5 8
*/
