/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,w,st;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
priority_queue<A> q;
vector<A> g[5500];
int dis[110][5500];
int main()
{
    int n,m,k,Min,i,u,v,w,st,j;
    scanf("%d %d %d",&n,&m,&k);
    for(i=1;i<=m;i++){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w,0});
        g[v].push_back({u,w,0});
    }
    for(i=1;i<=n;i++){
        for(j=0;j<=k;j++){
            dis[j][i]=1<<30;
        }
    }
    dis[0][1]=0;
    q.push({1,0,0});
    while(!q.empty()){
        u=q.top().u;
        w=q.top().w;
        st=q.top().st;
        q.pop();
        if(u==n && st==0){
            goto jump;
        }
        for(auto x:g[u]){
            if(st<k && dis[st+1][x.u]>dis[st][u]+x.w/2){
                dis[st+1][x.u]=dis[st][u]+x.w/2;
                q.push({x.u,dis[st+1][x.u],st+1});
            }
            if(dis[st][x.u]>dis[st][u]+x.w){
                dis[st][x.u]=dis[st][u]+x.w;
                q.push({x.u,dis[st][x.u],st});
            }
        }
    }
    jump:;
    Min=1<<30;
    for(i=1;i<=k;i++){
        Min=min(Min,dis[i][n]);
    }
    printf("%d\n",dis[0][n]);
    printf("%d\n",Min);
    printf("%d\n",dis[0][n]-Min);
    return 0;
}
/*
6 8 1
1 2 4
1 4 2
2 3 4
2 4 6
3 6 6
4 3 12
4 5 10
5 6 4
*/
