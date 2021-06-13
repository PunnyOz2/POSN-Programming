/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
vector<pair<int,char>> g[45000];
int cou=0;
int ans[250][250];
int n,m;
void dfs(int u,int i,int j){
    for(auto x:g[u]){
        if(x.second=='U'){
            if(i-1>=0){
                ans[i-1][j]=x.first;
                cou++;
                dfs(x.first,i-1,j);
            }
        }
        if(x.second=='L'){
            if(j-1>=0){
                ans[i][j-1]=x.first;
                cou++;
                dfs(x.first,i,j-1);
            }
        }
        if(x.second=='R'){
            if(j+1<m){
                ans[i][j+1]=x.first;
                cou++;
                dfs(x.first,i,j+1);
            }
        }
        if(x.second=='D'){
            if(i+1<n){
                ans[i+1][j]=x.first;
                cou++;
                dfs(x.first,i+1,j);
            }
        }
    }
}
int main()
{
	int i,v,rela,j,u;
	scanf("%d %d",&n,&m);
	for(i=0;i<m*n-1;i++){
        scanf("%d %c %d",&v,&rela,&u);
        g[u].push_back({v,rela});
        if(rela=='U')rela='D';
        else if(rela=='L')rela='R';
        g[v].push_back({u,rela});
	}
	for(i=0;i<m*n-1;i++){
        ans[n-1][m-1]=i;
        cou=1;
        dfs(i,n-1,m-1);
        if(cou==n*m-1){
            for(i=0;i<n;i++){
                for(j=0;j<m;j++)
                    printf("%d ",ans[i][j]);
                printf("\n");
            }
            break;
        }
	}
    return 0;
}
/*
3 2
1 U 5
0 U 3
4 L 2
0 L 1
5 U 2

0 1
3 5
4 2
*/
