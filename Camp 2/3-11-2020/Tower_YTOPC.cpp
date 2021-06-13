/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
queue<int> q;
int dis[100100];
vector<int> g[100100];
int main()
{
    int p,n,m,i,a,b,u,Max=1;
    scanf("%d %d %d",&p,&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        g[a].push_back(b);
    }
    for(i=1;i<=n;i++)dis[i]=1<<30;
    q.push(1);
    dis[1]=0;
    while(!q.empty()){
        u=q.front();
        q.pop();
        for(auto x:g[u]){
            if(dis[x]>dis[u]+1 && dis[u]<p){
                q.push(x);
                dis[x]=dis[u]+1;
                Max=max(Max,x);
            }
        }
    }
    printf("%d\n",Max);
    return 0;
}
/*
2 6 5
1 2
1 3
2 5
3 4
5 6
*/
