#include<bits/stdc++.h>
using namespace std;
struct A{
    long long u,v,w,i;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
priority_queue<A> q;
vector<A>ans;
long long p[100100];
A super[300100];
long long tt[100100],mark[100100];
long long fin(long long i){
    if(p[i]==i)return i;
    return p[i]=fin(p[i]);
}
int main(){
    long long n,m,k,i,u,v,w,state,id,pu,pv,Min,ansstate,now,MM,ansst2;
    scanf("%lld %lld %lld",&n,&m,&k);
    for(i=1;i<=n;i++)p[i]=i;
    for(i=1;i<=m;i++){
        scanf("%lld %lld %lld",&u,&v,&w);
        q.push({u,v,w,i});
    }
    state=0;
    Min=1<<30;
    ansstate=0;
    now=0;
    while(!q.empty()){
        u=q.top().u;
        v=q.top().v;
        w=q.top().w;
        id=q.top().i;
        q.pop();
        pu=fin(u);
        pv=fin(v);
        if(pu!=pv){
            p[pu]=pv;
            state++;
            now+=w;
            ans.push_back({u,v,w,id});
        }
    }
    printf("%lld\n",now);
    printf("%lld\n",n-1);
    for(i=0;i<n-1;i++){
        printf("%lld\n",ans[i].i);
    }
    long long temp=n-1-ansstate;
    printf("%lld\n",0);
}
/*
5 8 3
5 3 4
3 2 9
5 2 3
5 1 2
4 2 9
5 4 1
2 1 10
4 3 1
5 1
5 10
1 7

6 8 1
4 5 2
3 1 5
6 1 3
2 5 10
2 1 8
2 6 2
6 3 10
1 4 8
4 9

*/
