/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> g[200100];
int dis[200100];
queue<int> h;
int main()
{
    int n,m,nn,u,num,i,q,j,st,en;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d",&nn);
        for(j=0;j<nn;j++){
            scanf("%d",&num);
            g[i+n].push_back(num);
            g[num].push_back(i+n);
        }
    }
    scanf("%d",&q);
    while(q--){
        for(i=1;i<=n*2;i++){
            dis[i]=1<<30;
        }
        scanf("%d %d",&st,&en);
        dis[st]=0;
        h.push({st});
        while(!h.empty()){
            u=h.front();
            h.pop();
            for(auto x:g[u]){
                if(dis[x]>dis[u]+1)dis[x]=dis[u]+1,h.push(x);
            }
        }
        printf("%d\n",dis[en]/2);
    }
    return 0;
}
/*
9 3
4 1 2 3 4
3 4 5 6
4 6 7 8 9
4
1 9
2 7
4 1
2 5
*/
