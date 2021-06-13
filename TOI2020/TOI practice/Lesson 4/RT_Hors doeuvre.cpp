#include<bits/stdc++.h>
using namespace std;
int cou[100100],pp[100100];
int mark[100100];//mark of line
vector<int> g[100100];
void dfs(int u,int p){
    int Max=0,son;
    if(g[u].size()==1){cou[u]=1;return;}
    for(auto x:g[u]){
        if(x==p)continue;
        dfs(x,u);
        if(Max<cou[x]){
            Max=cou[x];
            son=x;
        }
    }
    pp[son]=u;
    cou[u]=Max+1;
}
int id;
int ans[100100];
void dfs2(int u,int p){
    mark[u]=id;
    if(g[u].size()==1)return;
    for(auto x:g[u]){
        if(x==p)continue;
        if(pp[x]==u)dfs2(x,u);
    }
    for(auto x:g[u]){
        if(x==p)continue;
        if(pp[x]==u)continue;
        dfs2(x,u);
        id++;
        ans[id]=-cou[x];
    }
}
int main(){
    int n,i,u,v;
    scanf("%d",&n);
    for(i=1;i<=n;i++)pp[i]=i;
    for(i=1;i<n;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,-1);
    id=1;
    ans[1]=-cou[1];
    dfs2(1,-1);
    printf("%d\n",id);
    sort(ans+1,ans+id+1);
    for(i=1;i<=id;i++)printf("%d\n",-ans[i]);
    return 0;
}
/*
7
1 2
1 3
3 4
4 5
3 6
6 7
*/
