/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long u,v,w;
    bool operator<(const A&o)const{
        return w<o.w;
    }
};
priority_queue<A> q;
long long p[100100];
long long fin(long long i){
    if(p[i]==i)return i;
    return p[i]=fin(p[i]);
}
int main()
{
    long long n,m,u,v,i,pu,pv,w,j,co=0,Q,num,st,en,cou;
    long long dis,ans=0,sum=0;
    scanf("%lld %lld",&n,&m);
    for(i=1;i<=n;i++)p[i]=i;
    for(i=1;i<=m;i++){
        scanf("%lld %lld %lld",&u,&v,&w);
        q.push({u,v,w});
    }
    scanf("%lld %lld %lld",&st,&en,&cou);
    while(!q.empty()){
        u=q.top().u;
        v=q.top().v;
        w=q.top().w;
        q.pop();
        pu=fin(u);
        pv=fin(v);
        if(pu!=pv){
            p[pu]=pv;
        }
        if(fin(st)==fin(en)){
            printf("%lld\n",cou/(w-1) + (bool)(cou%(w-1)!=0));
            break;
        }
    }
    return 0;
}
/*
7 10
1 2 30
1 3 15
1 4 10
2 4 25
2 5 60
3 4 40
4 7 35
3 6 20
5 7 20
7 6 30
1 7 99
*/
