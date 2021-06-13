/*
    TASK: AP_tree
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100100],sum,mi;
vector<int> g[100100];
void dfs(int u,int p){
    for(auto x:g[u]){
        if(x==p) continue;
        dfs(x,u);
        a[u]+=a[x];
    }
    mi = min(mi,abs(sum-2*a[u]));
}
int main()
{
    int q,n,i,r,s;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(i=0;i<n-1;i++){
            scanf("%d %d",&r,&s);
            g[r].push_back(s),g[s].push_back(r);
        }
        sum=0,mi=1e18;
        for(i=1;i<=n;i++)
            scanf("%lld",&a[i]),sum+=a[i];
        dfs(1,0);
        printf("%lld\n",mi);
        for(i=1;i<=n;i++) g[i].clear();
        memset(a,0,sizeof a);
    }
    return 0;
}
/*
2
6
1 2
1 3
1 5
5 6
6 4
2 1 3 3 4 6
3
1 2
1 3
10 4 3
*/
