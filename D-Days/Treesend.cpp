/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,child;
    bool operator<(const A&o)const{
        return child<o.child;
    }
};
vector<int> g[300100];
int child[300100],a,b,n;
int dfs(int u,int p){
    int sum=0;
    for(auto x:g[u]){
        if(x==b || x==a);
        if(x==p)continue;
        sum+=dfs(x,u);
    }
    child[u]=sum;
    return sum+1;
}
int mark[300100];
int main()
{
    int i,u,v;
    scanf("%d %d %d",&n,&a,&b);
    for(i=0;i<n-1;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    mark[a]=mark[b]=1;
    dfs(a,-1);
    dfs(b,-1);
    q.push({a,child[a]});
    q.push({b,child[b]});
    while(!q.empty()){

    }
    return 0;
}
