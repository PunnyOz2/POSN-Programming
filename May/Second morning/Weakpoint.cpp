/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dp[500100],in[500100],n,m,i,u,v,st;
vector<int> g[500100];
void dfs(int u,int p){
    int i;
    for(auto x:g[u]){
        if(x==p||in[x]<in[u])continue;
        in[x]--;
        in[u]--;
        dp[x]+=dp[u];
        if(in[x]==1){
            dfs(x,u);
        }
    }
}
int main()
{
    scanf("%d %d",&n,&st);
    for(i=1;i<=n;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
        in[u]++;
        in[v]++;
        dp[i]=1;
    }
    for(i=1;i<=n;i++){
        if(in[i]==1){
            in[i]--;
            dfs(i,-1);
        }
    }
    int ans=0,ansnode;
    if(in[st]>0){
        sort(g[st].begin(),g[st].end());
        for(auto x:g[st]){
            if(ans<dp[x]-1)ans=dp[x]-1,ansnode=x;
        }
        for(i=1;i<=n;i++){
            if(in[i]>0){
                if(i!=st){
                    if(ans<dp[i]-1)ans=dp[i]-1,ansnode=i;
                }
            }
        }
        printf("%d %d\n",ansnode,ans);
    }
    else{
        for(auto x:g[st]){
            if(dp[x]>dp[st]){
                if(ans<n-dp[st]-1)ans=n-dp[st]-1,ansnode=x;
            }
            else{
                if(ans<dp[x]-1)ans=dp[x]-1,ansnode=x;
            }
        }
        printf("%d %d\n",ansnode,ans);
    }
    return 0;
}
/*
12 4
1 2
1 6
1 7
1 12
6 8
6 9
2 3
2 10
10 11
3 4
4 5
5 12

*/
