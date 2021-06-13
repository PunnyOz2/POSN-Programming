/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int cou,depth[100100],from[100100],ans[100100];
vector<int> g[100100];
void dfs(int u,int p){
    depth[u]=0;
    for(auto x:g[u]){
        if(x==p)continue;
        dfs(x,u);
        if(depth[u]<depth[x])depth[u]=depth[x],from[u]=x;
    }
    depth[u]++;
}
void dfs2(int u,int p,int ch){
    if(ch==0)ans[cou++]=depth[u];
    for(auto x:g[u]){
        if(x==p)continue;
        if(x==from[u])dfs2(x,u,1);
        else dfs2(x,u,0);
    }
}
int main()
{
	int n,u,v,i;
	scanf("%d",&n);
	for(i=0;i<n-1;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
	}
	dfs(1,-1);
	dfs2(1,-1,0);
	sort(ans,ans+cou);
	printf("%d\n",cou);
	for(i=cou-1;i>=0;i--)printf("%d\n",ans[i]);
    return 0;
}
/*
7
1 2
1 3
3 4
4 5
3 6
6 7


*/
