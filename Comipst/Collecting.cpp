/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long u,w,lv;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
priority_queue<A> q;
vector<A> g[50100];
long long a[50100],dis[50100][50];
int main()
{
    long long n,m,l,st,en,i,u,v,lv,w,j;
    scanf("%lld %lld %lld",&n,&m,&l);
    scanf("%lld %lld",&st,&en);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(i=1;i<=m;i++){
        scanf("%lld %lld %lld",&u,&v,&w);
        g[u].push_back({v,w,0});
    }
    for(i=1;i<=n;i++)
        for(j=0;j<=30;j++)
            dis[i][j]=1<<30;
    q.push({st,0,0});
    while(!q.empty()){
        u=q.top().u;
        w=q.top().w;
        lv=q.top().lv;
        q.pop();
        if(lv==a[en] && u==en){
            printf("%lld\n",w);
            return 0;
        }
        for(auto x:g[u]){
            if(a[x.u]==lv+1 && dis[x.u][lv+1]>w+x.w)dis[x.u][lv+1]=w+x.w,q.push({x.u,dis[x.u][lv+1],lv+1});
            else if(dis[x.u][lv]>w+x.w)dis[x.u][lv]=w+x.w,q.push({x.u,dis[x.u][lv],lv});
        }
    }
    printf("-1\n");
    return 0;
}
/*
6 8 3
1 6
0 2 1 1 4 3
1 2 20
1 3 80
3 2 100
2 4 30
4 2 40
2 6 25
2 5 15
5 6 50
*/
