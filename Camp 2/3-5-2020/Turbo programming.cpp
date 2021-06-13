/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,dis;
    bool operator<(const A&o)const{
        return dis>o.dis;
    }
};
priority_queue<A> q;
vector<A> g[1100];
int dis[1100];
int main()
{
    int n,m,Q,i,u,v,w;
    scanf("%d %d %d",&n,&m,&Q);
    for(i=1;i<=m;i++){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w});
    }
    for(i=1;i<=n;i++){
        dis[i]=1<<30;
    }
    q.push({1,0});
    dis[1]=0;
    while(!q.empty()){
        u=q.top().u;
        w=q.top().dis;
        q.pop();
        for(auto x:g[u]){
            if(dis[x.u]>dis[u]+x.dis){
                dis[x.u]=dis[u]+x.dis;
                q.push({x.u,dis[x.u]});
            }
        }
    }
    int en;
    while(Q--){
        scanf("%d",&en);
        if(dis[en]!=1<<30)printf("%d\n",dis[en]);
        else printf("-1\n");
    }
    return 0;
}
