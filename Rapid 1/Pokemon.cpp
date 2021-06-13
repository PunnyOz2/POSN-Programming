/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int mark[1010];
vector<int> g[1010];
int a[1000000];
int ch=0;
void dfs(int u){
    mark[u]=1;
    for(auto x:g[u]){
        if(mark[x]==1){ch=1;return;}
        dfs(x);
    }
    mark[u]=0;
    return ;
}
int degin[1010];
queue<int> q;
int main()
{
	int m,i,u,v;
	scanf("%d",&m);
	for(i=0;i<m;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        degin[v]++;
	}
	for(i=0;i<=999;i++){
	    if(degin[i]==0)q.push(i);
	}
	while(!q.empty()){
        u=q.front();
        q.pop();
        for(auto x:g[u]){
            degin[x]--;
            if(degin[x]==0)q.push(x);
        }
	}
    for(i=0;i<=999;i++)
        if(degin[i]!=0){printf("BUG\n");return 0;}
	printf("OK\n");
    return 0;
}
/*
3
000 001
001 002
000 002

3
000 010
010 025
025 010

*/
