/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> g[1010];
int dp[1010][4];
void play(int u,int old){
    int Max=0,temp;
    //printf("%d %d\n",u,old);
    dp[u][1]=1,dp[u][2]=1;
    if(g[u].size()==1 && u!=1){
        dp[u][0]=0;
        dp[u][1]=1;
        dp[u][2]=1;
        return;
    }
    for(auto x:g[u]){
        if(x==old)continue;
        play(x,u);
        dp[u][0]+=max(dp[x][0],max(dp[x][1],dp[x][2]));
        if(Max<dp[x][1]-dp[x][0])Max=dp[x][1]-dp[x][0],temp=x;
        dp[u][2]+=dp[x][0];
    }
    dp[u][2]+=Max;
    for(auto x:g[u]){
        if(x==old)continue;
        dp[u][1]+=dp[x][0];
    }
}
int main()
{
    int q,n,i,u,v;
    scanf("%d",&q);
    while(q--){
        memset(dp,0,sizeof dp);
        scanf("%d",&n);
        for(i=1;i<n;i++){
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        play(1,0);
        printf("%d\n",max(max(dp[1][0],dp[1][1]),dp[1][2]));
        for(i=1;i<=n;i++)g[i].clear();
    }
    return 0;
}
/*
2
7
1 2
2 3
4 2
2 5
5 6
6 7
4
1 2
2 4
4 3
*/
