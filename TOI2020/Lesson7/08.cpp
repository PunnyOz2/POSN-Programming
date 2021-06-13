#include<bits/stdc++.h>
using namespace std;
long long dp[10100][3];
long long a[10100];
vector<long long> g[10100];
void play(long long u,long long p){
    long long sum=0,Min=1<<30;
    dp[u][1]=a[u];
    if(g[u].size()==1){
        dp[u][2]=0;
    }
    for(auto x:g[u]){
        if(x==p)continue;
        play(x,u);
    }
    for(auto x:g[u]){
        if(x==p)continue;
        dp[u][1]+=min(dp[x][0],min(dp[x][1],dp[x][2]));
        dp[u][2]+=dp[x][0];
        sum+=dp[x][0];
        Min=min(Min,dp[x][1]-dp[x][0]);
    }
    dp[u][0]=min(dp[u][1],sum+Min);
}
int main(){
    long long n,i,u,v;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(i=1;i<n;i++){
        scanf("%lld %lld",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    play(1,-1);
//    for(i=1;i<=n;i++){
//        printf("%d %d %d\n",dp[i][0],dp[i][1],dp[i][2]);
//    }
    printf("%lld\n",min(dp[1][0],dp[1][1]));
    return 0;
}
/*
6
4
9
1
20
5
3
2 1
3 2
2 4
5 4
4 6
*/
