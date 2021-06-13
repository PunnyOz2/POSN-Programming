/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[100003];
struct A{
    int i,j,w;
    bool operator<(const A& o)const{
        return w<o.w;
    }
};
vector<A> g;
int p[100003];
int fin(int i){
    if(p[i]==i)return i;
    return p[i]=fin(p[i]);
}
int main()
{
    int n,m,i,u,v,w,pu,pv;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        p[i]=i;
    }
    scanf("%d",&m);
    for(i=1;i<=m;i++){
        scanf("%d %d",&u,&v);
        g.push_back({u,v,a[u]+a[v]});
    }
    sort(g.begin(),g.end());
    int sum=0;
    for(i=0;i<g.size();i++){
        pu=fin(g[i].i);
        pv=fin(g[i].j);
        w=g[i].w;
        if(pu!=pv){
            p[pu]=pv;
            sum+=w;
        }
    }
    printf("%d\n",sum);
    return 0;
}
