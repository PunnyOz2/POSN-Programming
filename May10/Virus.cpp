/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100100],dis[100100];
vector<long long> b[300100];
vector<long long> g[100100];
queue<long long> q;
priority_queue<long long> h;
int main()
{
    long long n,m,k,i,u,v;
    scanf("%lld %lld %lld",&n,&m,&k);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(i=1;i<=m;i++){
        scanf("%lld %lld",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    q.push(k);
    memset(dis,-1,sizeof dis);
    dis[k]=0;
    while(!q.empty()){
        u=q.front();
        q.pop();
        for(auto x:g[u]){
            if(dis[x]==-1)dis[x]=dis[u]+1,q.push(x),b[dis[x]].push_back(a[x]);
        }
    }
    long long sum=0;
    for(i=1;i<=n;i++){
        if(dis[i]==-1 && a[i]>0)sum+=a[i];
    }
    for(i=300000;i>0;i--){
        for(auto x:b[i]){
            h.push(x);
        }
        if(!h.empty()){
            if(h.top()<0)continue;
            sum+=h.top();
            h.pop();
        }
    }
    printf("%lld\n",sum);
    return 0;
}
/*
5 5 2
5 8 2 10 7
1 2
2 4
1 3
1 4
4 5
*/
