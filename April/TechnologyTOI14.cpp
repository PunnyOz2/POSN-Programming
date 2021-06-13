/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> g[100100];
int in[100100];
int in2[100100];
queue<int> dfs;
struct A{
    int u,Min;
    bool operator<(const A&o)const{
        return Min>o.Min;
    }
};
priority_queue<A> dfs2;
int mark[100100];
int dp[100100];
int visited[100100];
int tech[100100];
int techlis[10100];
void dfsfunc(int u){
    dp[u]=tech[u];
    visited[u]=1;
    for(auto x:g[u]){
        if(visited[x]==0 && mark[x]==1)dfsfunc(x);
        if(visited[x]==1)dp[u]=min(dp[u],dp[x]);
    }
}
int main()
{
	int n,k,t,i,need,j,u;
	scanf("%d %d %d",&n,&k,&t);
	for(i=1;i<=n;i++){
        scanf("%d %d",&tech[i],&need);
        techlis[tech[i]]++;
        for(j=1;j<=need;j++){
            scanf("%d",&u);
            g[u].push_back(i);
            in[i]++;
            in2[i]++;
        }
	}
	techlis[k+1]=1;
	for(i=1;i<=n;i++){
        if(in[i]==0)dfs.push(i);
	}
	while(!dfs.empty()){
        u=dfs.front(),dfs.pop();
        mark[u]=1;
        for(auto x:g[u]){
            in[x]--;
            if(in[x]==0)dfs.push(x);
        }
	}
	for(i=1;i<=n;i++){
        if(in2[i]==0){
            dfs2.push({i,dp[i]});
            dfsfunc(i);
        }
	}
	while(!dfs2.empty() && t--){
        u=dfs2.top().u,dfs2.pop();
        techlis[tech[u]]--;
        for(auto x:g[u]){
            in2[x]--;
            if(in2[x]==0 && dp[x]!=0)dfs2.push({x,dp[x]});
        }
	}
	for(i=1;i<=k+1;i++){
        if(techlis[i]!=0){
            if(i==1)printf("-1\n");
            else printf("%d\n",i-1);
            break;
        }
	}
    return 0;
}
/*
6 5 4
1 0
5 1 1
2 1 2
4 2 3 5
3 1 6
2 1 1

7 4 7
3 1 2
1 0
4 2 7 1
1 1 5
2 1 2
3 1 4
4 1 6
*/
