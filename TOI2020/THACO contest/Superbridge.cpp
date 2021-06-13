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
long long tt[300100],mark[100100];
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
    for(i=1;i<=k;i++){
        scanf("%lld %lld",&u,&w);
        super[i]={u,0,w,i};
    }
    sort(super+1,super+1+k);
    reverse(super+1,super+1+k);
    for(i=1;i<=k;i++)super[i].w+=super[i-1].w;
    state=0;
    if(n-1<=k)Min=super[n-1].w;
    else Min=1e18;
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
            MM=min(k,n-1-state);
            if(state+MM==n-1 && now+super[MM].w<Min){
                Min=now+super[MM].w;
                ansstate=state;
            }
        }
    }
    printf("%lld\n",Min);
    printf("%lld\n",ansstate);
    for(i=0;i<ansstate;i++){
        printf("%lld\n",ans[i].i);
    }
    long long temp=n-1-ansstate;
    printf("%lld\n",temp);
    for(i=1;i<=n;i++)p[i]=i;
    for(i=0;i<ansstate;i++){
        u=ans[i].u;
        v=ans[i].v;
        //printf(" %lld %lld\n",u,v);
        pu=fin(u);
        pv=fin(v);
        p[pu]=pv;
    }
    for(i=1;i<=n;i++)fin(i);
    long long cou=1;
    for(i=1;i<=temp;i++){
        u=super[i].u;
        id=super[i].i;
        pu=p[u];
        now=mark[pu];
        for(long long j=1;j<=n;j++){
            if(p[j]!=pu){printf("%lld %lld\n",id,j),p[j]=pu;break;}
        }
    }
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

3 2 2
1 2 4
1 3 4
1 1
1 1

10 9 9
1 2 2
1 3 2
1 4 2
1 5 2
1 6 2
1 7 2
1 8 2
1 9 2
1 10 2
1 3
1 3
1 1
1 1
1 1
1 1
1 1
1 1
1 1
*/
