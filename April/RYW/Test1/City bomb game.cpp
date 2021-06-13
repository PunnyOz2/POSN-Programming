/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int ans=-1;
int mark[1010],st,i,u,v;
vector<int> g[1010];
void dfs(int u,int p){
    int state=1;
    for(auto x: g[u]){
        if(x==p) continue;
        dfs(x,u);
        if(state&&mark[x]){
            state=0;
            if(u==st&&ans==-1)ans=x;
        }
    }
    mark[u]=state;
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&st);
	for(i=0;i<n-1;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
	}
	for(i=1;i<=1000;i++)sort(g[i].begin(),g[i].end());
	dfs(st,-1);
	if(ans!=-1){
        printf("First player wins traveling to city %d",ans);
	}
	else printf("First player loses");
    return 0;
}
/*
5 3
3 2
3 1
1 4
2 5

5 3
3 1
1 2
1 4
4 5
*/
