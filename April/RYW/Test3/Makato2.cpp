/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int cost[100100];
vector<int> g[100100];
void dfs(int u,int p){
    for(auto x:g[u]){
        if(x==p)continue;
        dfs(x,u);
        cost[u]^=cost[x];
    }
    return;
}
int Min=1<<30;
void dfs2(int u,int p){
    int sum=0,sum2=0;
    for(auto x:g[u]){
        if(x==p)continue;
        sum+=cost[x];
    }
    if(p!=-1){
        sum+=cost[1]^cost[u];
    }
    if(Min>sum)Min=sum;
    for(auto x:g[u]){
        if(x==p)continue;
        dfs2(x,u);
    }
}
int main()
{
    int n,i,u,v;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&cost[i]);
    for(i=0;i<n-1;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,-1);
    dfs2(1,-1);
    //for(i=1;i<=n;i++)printf("%d ",cost[i]);
    printf("%d\n",Min);
    return 0;
}
/*
5
7 3 8 5 2
4 3
1 5
3 2
3 1
*/
