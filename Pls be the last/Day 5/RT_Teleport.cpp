/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dis[11100][13];
struct A{
    int u,w;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
vector<A> g[11100];
struct B{
    int u,w,state;
    bool operator<(const B&o)const{
        return w>o.w;
    }
};
priority_queue<B> q;
int main()
{
    int n,m,k,tp,i,u,v,w,nn,num,j,state;
    scanf("%d %d %d %d",&n,&m,&k,&tp);
    for(i=0;i<m;i++){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(i=1;i<=n+k;i++){
        for(j=0;j<=10;j++)
            dis[i][j]=1<<30;
    }
    for(i=1;i<=k;i++){
        scanf("%d",&nn);
        for(j=1;j<=nn;j++){
            scanf("%d",&num);
            g[i+n].push_back({num,0});
            g[num].push_back({i+n,0});
        }
    }
    dis[1][0]=0;
    q.push({1,0,0});
    while(!q.empty()){
        u=q.top().u;
        w=q.top().w;
        state=q.top().state;
        q.pop();
        for(auto x:g[u]){
            if(x.u>n && state<tp){
                if(dis[x.u][state+1]>dis[u][state])dis[x.u][state+1]=dis[u][state],q.push({x.u,dis[x.u][state+1],state+1});
            }
            else if(x.u<=n && dis[x.u][state]>dis[u][state]+x.w)dis[x.u][state]=dis[u][state]+x.w,q.push({x.u,dis[x.u][state],state});
        }
    }
    int Min=1<<30;
    for(i=0;i<=tp;i++){
        Min=min(Min,dis[n][i]);
    }
    if(Min==1<<30)printf("-1\n");
    else printf("%d\n",Min);
    return 0;
}
/*
5 10 2 1
5 1 11
5 4 9
5 4 13
4 5 1
3 4 14
5 4 12
3 5 4
3 5 12
5 1 10
1 5 13
2 1 5
1 3
*/
