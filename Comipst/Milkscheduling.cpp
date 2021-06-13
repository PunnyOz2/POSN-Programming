/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long a[50100],tim[50100],in[50100],mark[50100];
vector<long long> g[50100];
queue<long long> q;
int main()
{
    freopen("msched.in","r",stdin);
    freopen("msched.out","w",stdout);
    long long n,m,i,j,u,v;
    scanf("%lld %lld",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        tim[i]=a[i];
    }
    for(i=1;i<=m;i++){
        scanf("%lld %lld",&u,&v);
        in[v]++;
        g[u].push_back(v);
    }
    long long Max=-1e9;
    for(i=1;i<=n;i++){
        if(in[i]==0)q.push(i),mark[i]=1;
    }
        while(!q.empty()){
            u=q.front();
            Max=max(Max,tim[u]);
            q.pop();
            for(auto x:g[u]){
                if(mark[x]==1)continue;
                in[x]--;
                tim[x]=max(tim[x],tim[u]+a[x]);
                if(in[x]==0)q.push(x);
            }
        }
    printf("%lld\n",Max);
    return 0;
}
/*
3 1
10
5
6
3 2
*/
