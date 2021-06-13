/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> g[500100];
int cou=0;
int in[500100];
int dp[500100];
int mark[500100];
queue<int> q;
int main()
{
	int n,st,u,v,i;
	scanf("%d %d",&n,&st);
	for(i=0;i<n;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
        in[u]++;
        in[v]++;
	}
	for(i=1;i<=n;i++){
        if(in[i]==1)q.push(i);
        dp[i]=1;
	}
	while(!q.empty()){
        u=q.front(),q.pop();
        mark[u]=1;
        for(auto x:g[u]){
            if(mark[x]==1)continue;
            in[x]--;
            dp[x]+=dp[u];
            if(in[x]==1)q.push(x);
        }
	}
	if(in[st]>1){
        int Max=-1,ans=1;
        if(ans==st)ans++;
        for(i=1;i<=n;i++){
            if(i==st)continue;
            if(Max<dp[i]-1)Max=dp[i]-1,ans=i;
        }
        printf("%d\n%d\n",ans,Max);
	}
	else{
        int Max=-1,ans=1;
        if(ans==st)ans++;
        sort(g[st].begin(),g[st].end());
        for(auto x:g[st]){
            if(dp[x]>dp[st]){
                if(Max<n-dp[st]-1)Max=n-dp[st]-1,ans=x;
            }
            else{
                if(Max<dp[x]-1)Max=dp[x]-1,ans=x;
            }
        }
        printf("%d\n%d\n",ans,Max);
	}
    return 0;
}
/*
12 8
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
