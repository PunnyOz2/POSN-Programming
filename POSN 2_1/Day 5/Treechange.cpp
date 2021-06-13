/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1200];
int i;
vector<int> g[1200];
int dfs(int u,int n){
    int ans=1,now;
    int Min1=1<<25,Min2=1<<26;
    for(auto x:g[n]){
        if(x!=u){
            now=dfs(n,x);
            ans+=now;
            now=dp[x]-now;
            if(now<Min2){
                if(now<=Min1)Min2=Min1,Min1=now;
                else Min2=now;
            }
        }
    }
    dp[n]=min(ans-1,(ans-1+Min1+Min2));
    return ans;
}
int main()
{
	int q,n,i,u,v;
	scanf("%d",&q);
	while(q--){
        scanf("%d",&n);
        for(i=0;i<n-1;i++){
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int Min=1<<30;
        for(i=1;i<=n;i++){
            dfs(0,i);
            Min=min(Min,dp[i]);
        }
        printf("%d\n",Min);
        for(i=1;i<=n;i++)
            g[i].clear();
	}
    return 0;
}
/*
2
3
2 1
1 3
*/
