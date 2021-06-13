/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int in[100100],lv[100100],p[25][100100],qs[100100];
vector<pair<int,int>> g[100100];
int LCA(int a,int b){
    int sum = qs[a]+qs[b],i;
    if(lv[a]<lv[b]) swap(a,b);
    for(i=20;i>=0;i--){
        if(lv[p[i][a]]>=lv[b])
            a = p[i][a];
    }
    if(a == b){
        return sum-(2*qs[a]);
    }
    for(i=20;i>=0;i--){
        if(p[i][a]!=p[i][b])
            a = p[i][a],b = p[i][b];
    }
    return sum-(2*qs[p[0][a]]);
}
void dfs(int u,int pp,int lvl){
    lv[u]=lvl;
    for(auto x:g[u]){
        if(x.first==pp) continue;
        qs[x.first] = qs[u]+x.second;
        p[0][x.first]=u;
        dfs(x.first,u,lvl+1);
    }
}
int main()
{
    int n,q,i,u,v,w,root,j;
    scanf("%d %d",&n,&q);
    for(i=0;i<n-1;i++){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w});
        in[v]++;
    }
    for(i=0;i<n;i++){
        if(in[i]==0){
            root=i; break;
        }
    }
    dfs(root,-1,1);
    for(i=1;i<=20;i++){
        for(j=0;j<n;j++){
            p[i][j] = p[i-1][p[i-1][j]];
        }
    }
//    for(i=0;i<n;i++)   printf("%d ",qs[i]);
    while(q--){
        scanf("%d %d",&u,&v);
        printf("%d\n",LCA(u,v));
    }
    return 0;
}
/*
5 4
0 1 5
0 2 5
1 3 3
1 4 3
0 2
4 2
2 3
3 4
*/
