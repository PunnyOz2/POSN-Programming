/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[10100],in[10100];
vector<long long> g[10100];
queue<long long> q;
long long mark[10100];
long long dfs(long long u){
    mark[u]=1;
    if(u==2)return 1;
    for(auto x:g[u]){
        if(mark[x]==1)continue;
        if(dfs(x)==1)return 1;
    }
    return 0;
}
int main()
{
    long long n,m,i,u,v,ch=0,chh=0;
    scanf("%lld %lld",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%lld %lld",&u,&v);
        g[u].push_back(v);
        in[v]++;
    }
    q.push(0);
    g[0].push_back(1);
    dp[0]=1;
    in[1]++;
    while(!q.empty()){
        u=q.front();
        q.pop();
        for(auto x:g[u]){
            in[x]--;
            dp[x]+=dp[u];
            if(dp[x]>1000000000)chh=1;
            dp[x]%=1000000000;
            if(in[x]==0)q.push(x);
        }
    }
    ch=dfs(1);
    if(ch==1 && in[2]>0){
        printf("inf\n");
    }
    else{
        if(chh==1)printf("%09lld\n",dp[2]);
        else printf("%lld\n",dp[2]);
    }
    return 0;
}
/*
6 3
2 3
1 2
3 2
3 2
4 2
5 6
3 4
6 5
*/
