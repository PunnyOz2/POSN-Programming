/*
    TASK: Plantation
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,w,f;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
vector<A> g[1100];
priority_queue<A> dijk;
int dis[1100][110]; //node & state
int a[1100];
int main()
{
    int q,n,m,u,v,w,i,c,s,e,j,f,mi;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        while(m--){
            scanf("%d %d %d",&u,&v,&w);
            g[u].push_back({v,w,0}),g[v].push_back({u,w,0});
        }
        scanf("%d %d %d",&c,&s,&e); //printf("%d %d %d\n",u,w,f);
        for(i=0;i<=1000;i++)
            for(j=0;j<=100;j++)
                dis[i][j]=1<<30;
        dis[s][0]=0;
        dijk.push({s,0,0});
        while(!dijk.empty()){
            u=dijk.top().v,w=dijk.top().w,f=dijk.top().f; dijk.pop();
            if(u==e) break;
            if(f+1<=c && w+a[u]<dis[u][f+1]){
                dis[u][f+1]=w+a[u];
                dijk.push({u,dis[u][f+1],f+1});
            }
            for(auto x: g[u]){
                if(f>=x.w && w<dis[x.v][f-x.w]){
                    dis[x.v][f-x.w]=w;
                    dijk.push({x.v,w,f-x.w});
                }
            }
        }
        mi=1<<30;
        for(i=0;i<=c;i++)
            mi=min(mi,dis[e][i]);
        if(mi==1<<30) printf("-99\n");
        else printf("%d\n",mi);
        for(i=0;i<n;i++) g[i].clear();
        while(!dijk.empty())dijk.pop();
    }

    return 0;
}
/*
2
5 5
10 10 20 12 13
0 1 9
0 2 8
1 2 1
1 3 11
2 3 7
10 0 3
*/
