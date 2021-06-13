/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int open[1010][1010];
int close[1010][1010];
struct A{
    int u,w;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
priority_queue<A> q;
vector<A> g[1010];
int dis[1010],a[1010];
int main()
{
    int Q,n,m,s,t,e,p,i,u,v,w,cc,temp;
    scanf("%d",&Q);
    while(Q--){
        scanf("%d %d",&n,&m);
        scanf("%d %d %d %d",&s,&e,&t,&p);
        for(i=1;i<=p;i++){
            scanf("%d",&a[i]);
        }
        for(i=1;i<=m;i++){
            scanf("%d %d %d",&u,&v,&w);
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }
        for(i=1;i<=n;i++){
            dis[i]=1<<30;
        }
        cc=0;
        for(i=1;i<p;i++){
            close[a[i]][a[i+1]]=cc;
            close[a[i+1]][a[i]]=cc;
            for(auto x:g[a[i]]){
                if(x.u==a[i+1]){w=x.w;break;}
            }
            open[a[i]][a[i+1]]=cc+w-1;
            open[a[i+1]][a[i]]=cc+w-1;
            cc+=w;
            printf("%d %d\n",close[a[i]][a[i+1]],open[a[i]][a[i+1]]);
        }
        dis[s]=t;
        q.push({s,t});
        while(!q.empty()){
            u=q.top().u;
            w=q.top().w;
            //printf(" %d %d\n",u,w);
            q.pop();
            for(auto x:g[u]){
                temp=w;
                if(close[u][x.u]<=w && w<open[u][x.u])temp=open[u][x.u];
                if(dis[x.u]>temp+x.w){
                    dis[x.u]=temp+x.w;
                    q.push({x.u,dis[x.u]});
                }
            }
        }
        printf("%d\n",dis[e]-t+1);
        for(i=1;i<=n;i++)g[i].clear();
        memset(close,0,sizeof close);
        memset(open,0,sizeof open);
    }
    return 0;
}
/*
2
6 5
1 6 20 4
5 3 2 4
1 2 2
2 3 8
2 4 3
3 5 15
3 6 10
*/
