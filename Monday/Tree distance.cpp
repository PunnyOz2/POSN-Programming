/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dp[50100][510],m,ans=0;
vector<int> g[50100];
void dfs(int u,int p,int now){
    if(now==m){ans++;return;}
    for(auto x:g[u]){
        if(x==p)continue;
        dfs(x,u,now+1);
    }
}
int main()
{
    int n,i,u,v,j,Min;
    scanf("%d %d",&n,&m);
    for(i=0;i<n-1;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(i=1;i<=n;i++){
        dfs(i,-1,0);
    }
    printf("%d\n",ans/2);
    return 0;
}
/*
5 2
1 2
2 3
3 4
2 5
*/
