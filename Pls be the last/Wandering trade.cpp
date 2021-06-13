/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
queue<int> q;
vector<int> g[1010];
int in[1010],in2[1010];
pair<int,int> input[10100];
int mark[1010];
int main()
{
    int n,m,Q,nn,i,u,v;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d %d",&u,&v);
        input[i]={u,v};
    }
    scanf("%d",&Q);
    while(Q--){
        scanf("%d",&nn);
        memset(mark,0,sizeof mark);
        memset(in,0,sizeof in);
        for(i=0;i<nn;i++){
            scanf("%d",&u);
            mark[u]=1;
        }
        for(i=0;i<m;i++){
            if(mark[input[i].first]==1 || mark[input[i].second]==1)continue;
            g[input[i].second].push_back(input[i].first);
            in[input[i].first]++;
        }
        for(i=1;i<=n;i++){
            if(in[i]==0)
                q.push(i);
        }
        while(!q.empty()){
            u=q.front();
            q.pop();
            for(auto x:g[u]){
                in[x]--;
                if(in[x]==0){
                    q.push(x);
                }
            }
        }
        int ch=0;
        for(i=1;i<=n;i++){
            if(in[i]>0)
                printf("%d ",i),ch=1;
            g[i].clear();
        }
        if(ch==0)printf("-1");
        printf("\n");
    }
    return 0;
}
/*
6 7
1 2
2 3

3 5
2 6
6 5
2 4
4 1
2
2 3 5
*/
