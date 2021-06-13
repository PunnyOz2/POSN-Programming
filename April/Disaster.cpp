/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> g[150];
int mark[100][100];
char ans[350];
int a[100];
int n;
void dfs(int u,int state){
    int i;
    ans[state]=u;
    if(state==n){
        for(i=0;i<=n;i++){
            printf("%c ",ans[i]);
        }
        exit(0);
    }
    for(auto x:g[u]){
        if(mark[u][x]!=1){
            mark[u][x]=mark[x][u]=1;
            dfs(x,state+1);
            mark[u][x]=mark[x][u]=0;
        }
    }
}
int main()
{
    int i;
    char u,v;
	scanf("%d",&n);
	for(i=0;i<n;i++){
        scanf(" %c %c",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
        a[u]++;
        a[v]++;
	}
	for(i=65;i<=90;i++)sort(g[i].begin(),g[i].end());
	int st=-1,mi=100;
	for(i=65;i<=90;i++){
        if(a[i]%2==1){
            st=i; break;
        }
        else if(a[i]>0)mi=min(mi,i);
    }
    if(st==-1) st=mi;
    dfs(st,0);
    return 0;
}
/*
6
AB
AE
BD
BC
CE
DE
*/
