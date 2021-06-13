/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u;
    double w;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
priority_queue<A> q;
vector<A> g[1010];
double dis[1010];
int mark[1010][1010];
int a[1010][2];
int main()
{
    int n,m,i,u,v,j;
    double MIN,temp,w,temp2;
    scanf("%d %d",&n,&m);
    scanf("%lf",&MIN);
    for(i=1;i<=n;i++){
        scanf("%d %d",&a[i][0],&a[i][1]);
        dis[i]=1<<30;
    }
    for(i=1;i<=m;i++){
        scanf("%d %d",&u,&v);
        mark[u][v]=1;
        mark[v][u]=1;
    }
    for(i=1;i<n;i++){
        for(j=i+1;j<=n;j++){
            temp2=(double)((double)a[i][0]-(double)a[j][0])*((double)a[i][0]-(double)a[j][0])+((double)a[i][1]-(double)a[j][1])*((double)a[i][1]-(double)a[j][1]);
            temp=sqrt(temp2);
            g[i].push_back({j,temp});
            g[j].push_back({i,temp});
        }
    }
    dis[1]=0;
    q.push({1,0});
    while(!q.empty()){
        u=q.top().u;
        w=q.top().w;
        q.pop();
        for(auto x:g[u]){
            if(mark[u][x.u]==1 && dis[x.u]-dis[u]>1e-6){
                dis[x.u]=dis[u];
                q.push({x.u,dis[x.u]});
            }
            if(1e-6<=MIN-x.w && dis[x.u]-dis[u]-x.w>1e-6){
                dis[x.u]=dis[u]+x.w;
                q.push({x.u,dis[x.u]});
            }
        }
    }
    if(dis[n]==1<<30)printf("-1\n");
    else printf("%d\n",(int)(dis[n]*1000));
    return 0;
}
/*
9 3
2.0
0 0
0 1
1 1
2 1
2 2
3 2
3 3
4 1
4 3
1 2
2 3
3 4
*/
