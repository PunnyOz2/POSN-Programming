#include<bits/stdc++.h>
using namespace std;
int in[100100],cut[100100],mark2[100100][3],uu,st;
vector<int> g[100100];
queue<pair<int,int>> Q;
void dfs(int u){
    for(auto x:g[u]){
        in[x]--;
        if(in[x]==0)dfs(x);
    }
}
int main()
{
    int n,m,q,i,u,v,opr,ch;
    scanf("%d %d %d",&n,&m,&q);
    for(i=1;i<=m;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        in[v]++;
    }
    while(q--){
        scanf("%d %d",&opr,&u);
        if(opr==1){
            in[u]=0;
            bfs(u);
        }
        if(opr==2){
            memset(mark2,0,sizeof mark2);
            if(u==1)Q.push({1,1});
            else Q.push({1,0});
            while(!Q.empty()){
                uu=Q.front().first;
                st=Q.front().second;
                //printf("%d %d\n",uu,st);
                mark2[uu][st]=1;
                Q.pop();
                for(auto x:g[uu]){
                    if(cut[x]!=0)continue;
                    //printf("%d %d %d\n",x,mark2[x][0],mark2[x][1]);
                    if(x==u && mark2[x][1]==0)Q.push({x,1});
                    else if(mark2[x][st]==0)Q.push({x,st});
                }
            }
            if(mark2[n][1]==1)printf("1\n");
            else printf("0\n");
            while(!Q.empty())Q.pop();
        }
    }
    return 0;
}
/*
5 6 8
1 2
2 3
2 4
4 3
1 3
3 5

2 4
1 2
2 4
2 3
2 5
1 3
2 4
2 3
*/
