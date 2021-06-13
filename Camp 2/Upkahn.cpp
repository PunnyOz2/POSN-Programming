/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
priority_queue<int> q;
int in[100100];
vector<int> g[100100],ans;
int main()
{
    int Q,n,m,i,u,v;
    scanf("%d",&Q);
    while(Q--){
        scanf("%d %d",&n,&m);
        for(i=1;i<=m;i++){
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
            in[v]++;
        }
        for(i=1;i<=n;i++){
            if(in[i]==0)q.push(-i);
        }
        while(!q.empty()){
            u=-q.top();
            ans.push_back(u);
            q.pop();
            for(auto x:g[u]){
                in[x]--;
                if(in[x]==0){
                    q.push(-x);
                }
            }
        }
        if(ans.size()==n){
            printf("Yes ");
            for(auto x:ans){
                printf("%d ",x);
            }
            printf("\n");
        }
        else{
            printf("No\n");
        }
        ans.clear();
        for(i=1;i<=n;i++)g[i].clear();
        memset(in,0,sizeof in);

    }
    return 0;
}
/*
2
5 5
1 2
1 3
2 4
3 5
4 5
5 6
1 2
1 3
2 4
3 5
4 5
4 1
*/
