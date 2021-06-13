#include<bits/stdc++.h>
using namespace std;
long long a[100100],p[100100];
struct A{
    long long u,v,w;
    bool operator<(const A&o)const{
        return w<o.w;
    }
};
vector<A> g;
int fin(int i){
    if(p[i]==i)return i;
    return p[i]=fin(p[i]);
}
int main(){
    long long n,u,v,i,m,Max,w,pu,pv;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        p[i]=i;
    }
    scanf("%lld",&m);
    for(i=1;i<=m;i++){
        scanf("%lld %lld",&u,&v);
        g.push_back({u,v,a[u]+a[v]});
    }
    sort(g.begin(),g.end());
    long long sum=0;
    for(i=0;i<m;i++){
        u=g[i].u;
        v=g[i].v;
        w=g[i].w;
        pu=fin(u);
        pv=fin(v);
        if(pu!=pv){
            p[pu]=pv;
            sum+=w;
        }
    }
    printf("%lld\n",sum);
    return 0;
}
/*
10
1 2 1 2 3 1 2 1 2 1
15
5 1
10 8
5 4
7 10
10 9
2 5
8 4
6 10
7 8
8 5
3 8
6 8
3 1
2 3
3 5
*/
