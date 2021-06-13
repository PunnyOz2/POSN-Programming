/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,w;
    bool operator<(const A&o)const{
        return w<o.w;
    }
};
priority_queue<A> q;
vector<A> g[3000];
int dis[3000];
int main()
{
    int n,m,peop,u,en,v,w,i;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    scanf("%d %d %d",&u,&en,&peop);
    q.push({u,1000000});
    while(!q.empty()){
        u=q.top().u;
        w=q.top().w;
        q.pop();
        if(u==en){
            if(peop%(w-1)!=0){
                printf("%d",peop/(w-1)+1);
            }
            else printf("%d\n",peop/(w-1));
            break;
        }
        for(auto x:g[u]){
            if(dis[x.u]<min(x.w,w))dis[x.u]=min(x.w,w),q.push({x.u,dis[x.u]});
        }
    }
    return 0;
}
/*
7 10
1 2 30
1 3 15
1 4 10
2 4 25
2 5 60
3 4 40
4 7 35
3 6 20
5 7 20
7 6 30
1 7 99
*/
