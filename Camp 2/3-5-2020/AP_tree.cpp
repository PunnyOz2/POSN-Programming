/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
vector<long long> g[100100];
long long sum[100100];
int a[100100][2];
void dfs(long long u,long long old){
    for(auto x:g[u]){
        if(x==old)continue;
        dfs(x,u);
        sum[u]+=sum[x];
    }
}
int main()
{
    long long q,n,temp,i,u,v,all,Min;
    scanf("%lld",&q);
    while(q--){
        all=0;
        scanf("%lld",&n);
        for(i=1;i<n;i++){
            scanf("%lld %lld",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
            a[i][0]=u;
            a[i][1]=v;
        }
        for(i=1;i<=n;i++){
            scanf("%lld",&sum[i]);
            all+=sum[i];
        }
        dfs(1,0);
        Min=1e18;
        for(i=1;i<=n;i++){
            temp=min(sum[a[i][0]],sum[a[i][1]]);
            Min=min(Min,abs(all-temp-temp));
        }
        printf("%lld\n",Min);
        for(i=1;i<=n;i++)g[i].clear();
    }
    return 0;
}
