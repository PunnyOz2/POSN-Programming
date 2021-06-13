/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int mark[10],n,m,cou=0;
vector<int> g[10];
void dfs(int u,int now){
    mark[u]=1;
    if(now==n){
        cou++;
    }
    for(auto x:g[u]){
        if(mark[x]==0){
            mark[x]=1;
            dfs(x,now+1);
            mark[x]=0;
        }
    }
}
int main()
{
    int u,v,i;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,1);
    printf("%d\n",cou);
    return 0;
}
/*
7 7
1 3
2 7
3 4
4 5
4 6
5 6
6 7
*/
