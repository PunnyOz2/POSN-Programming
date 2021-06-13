/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
map<vector<vector<int>>,int> mp;
vector<int> g[2000];
vector<vector<int>> gg;
int main()
{
    int Q,q,n,i,u,v;
    scanf("%d %d",&Q,&q);
    while(Q--){
        scanf("%d",&n);
        for(i=0;i<n-1;i++){
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for(i=1;i<=n;i++){
            g[i].push_back(i);
        }
        for(i=1;i<=n;i++){
            sort(g[i].begin(),g[i].end());
            gg.push_back(g[i]);
            g[i].clear();
        }
        mp[gg]++;
        gg.clear();
    }
    while(q--){
        scanf("%d",&n);
        for(i=0;i<n-1;i++){
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for(i=1;i<=n;i++){
            g[i].push_back(i);
        }
        for(i=1;i<=n;i++){
            sort(g[i].begin(),g[i].end());
            gg.push_back(g[i]);
            g[i].clear();
        }
        printf("%d\n",mp[gg]);
        gg.clear();
    }
    return 0;
}
/*
3 2
10
1 2
6 4
2 5
3 5
8 6
2 7
5 8
8 9
4 10
6
1 4
2 4
4 3
5 4
5 6
10
1 2
2 7
2 5
3 5
8 6
4 6
5 8
8 9
4 10
6
1 4
2 4
4 3
5 4
1 6
10
1 2
2 7
2 5
3 5
8 6
4 6
5 8
8 9
4 10
*/
