/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,w;
    bool operator<(const A& o)const{
        return w>o.w;
    }
};
vector<A> g[1200];
priority_queue<A> q;
int a[1200];
int dis[1200];
int edge[1200][1200];
pair< int,int > p[1200][1200];
int main()
{
	int Q,n,m,s,e,t,p2,u,v,w,i,j;
	scanf("%d",&Q);
	while(Q--){
        scanf("%d %d",&n,&m);
        scanf("%d %d %d %d",&s,&e,&t,&p2);
        for(i=1;i<=p2;i++){
            scanf("%d",&a[i]);
        }
        while(m--){
            scanf("%d %d %d",&u,&v,&w);
            g[u].push_back({v,w});
            g[v].push_back({u,w});
            edge[u][v]=edge[v][u]=w;
        }
        for(i=1;i<=n;i++)
            dis[i]=1e9;
        int last=0;
        for(i=2;i<=p2;i++)
        {
            p[a[i-1]][a[i]]=p[a[i]][a[i-1]]={last,edge[a[i-1]][a[i]]+last};
            last+=edge[a[i-1]][a[i]];
        }
        q.push({s,t});
        dis[s]=t;
        while(!q.empty()){
            u=q.top().v,w=q.top().w,q.pop();
            if(u == e)  break;
            for(auto x: g[u]){
                if(w>=p[u][x.v].first && w<=p[u][x.v].second){
                    if(p[u][x.v].second+x.w<dis[x.v])
                        dis[x.v]=p[u][x.v].second+x.w,q.push({x.v,dis[x.v]});
                }else{
                    if(w+x.w<dis[x.v]){
                        dis[x.v]=w+x.w,q.push({x.v,dis[x.v]});
                    }
                }
            }
        }
        printf("%d\n",dis[e]-t);
        for(i=1;i<=n;i++)g[i].clear();
        memset(edge,0,sizeof edge);
        memset(p,0,sizeof p);
        while(!q.empty())   q.pop();
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

8 9
1 5 5 5
1 2 3 4 5
1 2 8
2 3 10
2 7 4
3 4 23
3 6 5
4 8 4
4 5 5
6 8 3
6 7 40
*/
