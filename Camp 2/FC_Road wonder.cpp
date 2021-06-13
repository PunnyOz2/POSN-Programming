/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v,w;
};
vector<A> g;
int dis[1100],temp[1010];
int main()
{
    int n,m,k,t,i,u,v,w;
    scanf("%d %d %d %d",&n,&m,&k,&t);
    for(i=1;i<=m;i++){
        scanf("%d %d %d",&u,&v,&w);
        g.push_back({u,v,w});
    }
    for(i=1;i<=k;i++){
        scanf("%d %d %d",&u,&v,&w);
        g.push_back({u,v,-w});
    }
    while(t--){
        for(i=1;i<=n;i++){
            dis[i]=1<<30;
        }
        scanf("%d",&u);
        dis[u]=0;
        for(i=1;i<=n-1;i++){
            for(auto x:g){
                if(dis[x.u]!=1<<30 && dis[x.u]+x.w<dis[x.v]){
                    dis[x.v]=dis[x.u]+x.w;
                }
            }
        }
        for(i=1;i<=n;i++){
            temp[i]=dis[i];
        }
        for(auto x:g){
            if(dis[x.u]!=1<<30 && dis[x.u]+x.w<dis[x.v]){
                dis[x.v]=dis[x.u]+x.w;
            }
        }
        for(i=1;i<=n;i++){
            if(temp[i]!=dis[i] || dis[i]==1<<30)printf("-1 ");
            else printf("%d ",dis[i]);
        }
        printf("\n");
    }
    return 0;
}
/*
10 5 5 5
1 7 8
2 5 1
3 4 7
5 8 4
5 1 11
10 1 6
10 5 3
10 3 1
9 5 10
5 7 2
2
*/
