/*
    TASK: Vulgar
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> g[50100];
int color[5],mark[50100];
void dfs(int u,int col){
    if(mark[u]) return;
    color[col]++;
    mark[u]=1;
    for(auto x: g[u]){
        dfs(x,3-col);
    }
    return;
}
int main()
{
    int n,m,a,b,i,ans=0;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d",&a,&b);
        g[a].push_back(b),g[b].push_back(a);
    }
    for(i=1;i<=n;i++){
        if(mark[i]==0){
            color[1]=color[2]=0;
            dfs(i,1);
            if(color[2]>color[1]){swap(color[1],color[2]);}
            ans+=color[1]+(color[2]*3);
        }
    }
    printf("%d",ans);

    return 0;
}
/*
4 3
1 2
2 3
4 2
*/
