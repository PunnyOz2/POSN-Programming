/*
    TASK: Bipartite
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> g[100100];
int color[100100];
int dfs(int u,int col){
    if(color[u]!=0 && color[u]==col) return 1;
    if(color[u]!=0 && color[u]!=col) return 0;
    color[u]=col;
    for(auto x: g[u]){
        if( dfs(x,3-col)==0)
            return 0;
    }
    return 1;
}
int main()
{
    int q,n,m,i,u,v,ch;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&m);
        while(m--){
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        memset(color,0,sizeof color);
        ch=1;
        for(i=1;i<=n;i++){
            if(color[i]==0){
                if( dfs(i,1)==0){
                    ch=0;break;
                }
            }
        }
        printf(ch?"yes\n":"no");
        for(i=1;i<=n;i++)
            g[i].clear();
    }
    return 0;
}
/*
2
4 4
1 2
2 3
3 4
4 1
3 3
1 2
2 3
3 1
*/
