#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,w,past;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
priority_queue<A> q;
int dis[2010][2010];
struct B{
    int u,w;
};
vector<B> g[2010];
int main(){
    int n,st,en,m,Q,level,u,w,past,i,v,j,Min;
    scanf("%d %d %d %d",&n,&st,&en,&m);
    for(i=1;i<=m;i++){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w});
    }
    for(i=0;i<n;i++){
        for(j=0;j<=n;j++)dis[i][j]=1<<30;
    }
    q.push({st,0,0});
    dis[st][0]=0;
    while(!q.empty()){
        u=q.top().u;
        w=q.top().w;
        past=q.top().past;
        q.pop();
        for(auto x:g[u]){
            if(dis[x.u][past+1]>dis[u][past]+x.w){
                dis[x.u][past+1]=dis[u][past]+x.w;
                q.push({x.u,dis[x.u][past+1],past+1});
            }
        }
    }
    scanf("%d",&Q);
    while(Q--){
        scanf("%d",&level);
        Min=1<<30;
        for(i=1;i<=n;i++){
            if(dis[en][i]==1<<30)continue;
            //printf("%d %d\n",i,dis[en][i]);
            Min=min(Min,dis[en][i]+level*(i-1));
        }
        printf("%d\n",Min);
    }
    return 0;
}
/*
8 0 7 14
0 1 10
0 3 14
0 4 8
1 2 2
2 7 2
2 3 4
3 7 15
3 4 9
5 3 7
5 7 2
4 5 5
4 6 1
6 5 1
6 4 3
4
0 10 2 30
*/
