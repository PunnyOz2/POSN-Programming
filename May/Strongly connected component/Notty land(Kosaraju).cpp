/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
vector<int>g[100100],gt[100100];
int mark[100100],scc[100100],cnt=0;
stack<int>s;
void dfs(int u){
    if(mark[u])return ;
    mark[u]=1;
    for(auto x:g[u]){
        dfs(x);
    }
    s.push(u);
}
void dfs2(int u){
    if(mark[u])return;
    mark[u]=1;
    scc[u]=cnt;
    for(auto x:gt[u])
        dfs2(x);
}
int main()
{
    int n,m,k,i,j,r;
    scanf("%d %d %d",&n,&m,&k);
    for(i=1;i<=n;i++){
        scanf("%d",&j);
        while(j--){
            scanf("%d",&r);
            g[i].push_back(r),gt[r].push_back(i);
        }
    }
    for(i=1;i<=n;i++)
        if(!mark[i])dfs(i);
    memset(mark,0,sizeof mark);
    while(!s.empty()){
        i=s.top();
        s.pop();
        if(mark[i]!=0)continue;
        scc[i]=++cnt;
        dfs2(i);
    }
    int q,u,v;
    while(k--){
        scanf("%d %d",&u,&v);
        if(scc[u]==scc[v])printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
/*
4 4 2
2 2 4
1 3
1 1
0
3 1
1 4
*/
