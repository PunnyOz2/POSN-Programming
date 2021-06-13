#include <bits/stdc++.h>
using namespace std;
struct A{
    int u,w;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
priority_queue<A>q;
int dis[10100],dis2[10100];
vector<A>g[10100];
int main(){
    int n,m,st,en,budget,i,u,v,w,Min,ans;
    scanf("%d %d",&n,&m);
    scanf("%d %d %d",&st,&en,&budget);
    for(i=1;i<=m;i++){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(i=0;i<n;i++){
        dis[i]=1<<30;
        dis2[i]=1<<30;
    }
    dis[en]=0;
    q.push({en,0});
    while(!q.empty()){
        u=q.top().u;
        w=q.top().w;
        q.pop();
        for(auto x:g[u]){
            if(dis[x.u]>dis[u]+x.w){
                dis[x.u]=dis[u]+x.w;
                q.push({x.u,dis[x.u]});
            }
        }
    }
    dis2[st]=0;
    q.push({st,0});
    while(!q.empty()){
        u=q.top().u;
        w=q.top().w;
        q.pop();
        for(auto x:g[u]){
            if(dis2[u]+x.w<=budget && dis2[x.u]>dis2[u]+x.w){
                dis2[x.u]=dis2[u]+x.w;
                q.push({x.u,dis2[x.u]});
            }
        }
    }
//    for(i=0;i<n;i++)printf("%d ",dis2[i]);
//    printf("\n");
    if(dis2[en]!=1<<30){
        printf("%d %d %d\n",en,dis2[en],0);
    }
    else{
        Min=1<<30;
        for(i=0;i<n;i++){
            if(dis2[i]!=1<<30 && dis[i]<Min){
                Min=dis[i];
                ans=i;
            }
        }
        printf("%d %d %d\n",ans,dis2[ans],dis[ans]);
    }
}
/*
8 11
0 5 200
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
