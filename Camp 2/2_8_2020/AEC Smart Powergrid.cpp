#include <bits/stdc++.h>
using namespace std;
int g[110][110],s,t,dis[110],i,j,p[110],n,m;
queue<int> q;
bool play(){
    memset(dis,-1,sizeof dis);
    dis[s]=0;
    q.push(s);
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(i=1;i<=n;i++){
            if(g[now][i]>0 && dis[i]==-1){
                dis[i]=dis[now]+1;
                p[i]=now;
                q.push(i);
            }
        }
    }
    return dis[t]>0;
}
int maxflow(int u,int flow){
    if(u == s){
        return flow;
    }
    flow=maxflow(p[u],min(flow,g[p[u]][u]));
    g[p[u]][u]-=flow;
    g[u][p[u]]+=flow;
    return flow;
}
int main(){
    int u,v,w,ans=0;
    scanf("%d %d %d %d",&n,&m,&s,&t);
    while(m--){
        scanf("%d %d %d",&u,&v,&w);
        g[u][v]=w;
    }
    while(play()){
        ans+=maxflow(t,1<<28);
    }
    printf("%d\n",ans);
}
/*
4 5
1 4
1 2 5
2 4 10
3 4 19
2 3 5
1 3 12
*/
