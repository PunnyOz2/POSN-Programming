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
};
int main()
{
    int n;
    scanf("%d",&n);
    for(i=0;i<n-1;i++){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(i=1;i<n;i++)dis[i]=1<<30;
    q.push({n,0});
    while(!q.empty()){
        u=q.top();
        q.pop();
        for(auto x:g[u]){
            dis[x.u]=min(dis[x.u],dis[u]+x.w);
        }
    }
    return 0;
}
