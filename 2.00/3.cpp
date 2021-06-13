#include <bits/stdc++.h>
using namespace std;
int a[550][550],mark[550][550];
vector<int> g[550];
void dfs(int n,int nn){
    for(auto x:g[nn]){
        if(mark[n][x]!=1){
        a[n][x]=mark[n][x]=1;
        dfs(n,x);
        }
    }
}
int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            if(a[i][j]==1) g[i].push_back(j);
        }
    for(i=1;i<=n;i++)dfs(i,i);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
}
/*
4
0 0 1 0
1 0 0 1
0 0 0 0
0 1 0 0
*/
