/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>g;
map<vector<pair<int,int>>,int>mp;
int main(){
    int n,q,k,i,u,v;
    scanf("%d %d",&k,&q);
    while(k--){
        scanf("%d",&n);
        for(i=0;i<n-1;i++){
            scanf("%d %d",&u,&v);
            if(u>v)swap(u,v);
            g.push_back({u,v});
        }
        sort(g.begin(),g.end());
        mp[g]++;
        g.clear();
    }
    while(q--){
        scanf("%d",&n);
        for(i=0;i<n-1;i++){
            scanf("%d %d",&u,&v);
            if(u>v)swap(u,v);
            g.push_back({u,v});
        }
        sort(g.begin(),g.end());
        printf("%d\n",mp[g]);
        g.clear();
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
