/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> in[100100],g[100100];
int e[200100],l[200100],h[100100],rmg[20][200100];
int cnt=0;
void dfs(int u,int le){
    e[cnt]=u;l[cnt]=le,cnt++;
    for(auto x:g[u]){
        dfs(x,le+1);
        e[cnt]=u;l[cnt]=le;cnt++;
    }
}
int main()
{
    int n,q,u,v,i,root,j,a,b,k;
    scanf("%d",&n);
    for(i=0;i<n-1;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back(v),in[v].push_back(u);
    }
    for(i=1;i<=n;i++){
        if(in[i].size()==0){
            root=i;break;
        }
    }
    dfs(root,0);
    memset(h,-1,sizeof h);
    for(i=0;i<cnt;i++){
        if(h[e[i]]==-1){
            h[e[i]]=i;
        }
        rmg[0][i]=i;
    }
    for(i=1;(1<<i)<=cnt;i++){
        for(j=0;j+(1<<i)<=cnt;j++){
            if(l[ rmg[i-1][j] ]<l[ rmg[i-1][j+(1<<(i-1))] ]){
                rmg[i][j]=rmg[i-1][j];
            }
            else rmg[i][j]=rmg[i-1][j+(1<<(i-1))];
        }
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&a,&b);
        if(h[a] > h[b])swap(a,b);
        k=log2( h[b]-h[a]+1 );
        if(l[ rmg[k][h[a]] ]<l[ rmg[k][h[b]-(1<<k)+1] ])printf("%d\n",e[ rmg[k][h[a]] ]);
        else printf("%d\n",e[ rmg[k][h[b] -(1<<k)+1 ]]);
    }
    return 0;
}
/*
13 1 2 1 3 2 9 2 6 2 8 6 10 6 5 3 7 7 11 7 13 13 4 13 12 5 10 5 11 12 9 7 10 8 9 8
*/
