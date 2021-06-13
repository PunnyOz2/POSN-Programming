/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,p,q;
    double d;
    bool operator<(const A&o)const{
        return d>o.d;
    }
};
priority_queue<A> q;
vector<A> g[1000002];
double cost[1000003];
int main()
{
    int n,i,u,v;
    scanf("%d",&n);
    for(i=0;i<n-1;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back({v,0,0,0});
        g[v].push_back({u,0,0,0});
    }
    for(i=1;i<=n;i++){
        scanf("%d",cost[i]);
    }
    q.push({})
    return 0;
}
