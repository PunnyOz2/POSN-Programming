/*
    TASK: treeinc
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> g[300100];
int dp[300100];
int main()
{
    int n,i,u,v,Ma=-1;
    scanf("%d",&n);
    for(i=0;i<n-1;i++){
        scanf("%d %d",&u,&v);
        if(u>v) swap(u,v);
        g[v].push_back(u);
    }
    for(i=1;i<=n;i++){
        for(auto x:g[i])
            dp[i]=max(dp[i],dp[x]);
        dp[i]++;
        Ma=max(Ma,dp[i]);
    }
    printf("%d\n",Ma);
    return 0;
}
/*
9
1 2
2 9
1 7
6 8
2 6
3 9
4 9
5 4
*/
