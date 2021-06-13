#include<bits/stdc++.h>
using namespace std;
struct A{
    long long u,w;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
priority_queue<A> q;
struct B{
    long long u,dif,w;
};
vector<B>g[100100];
long long dis[100100];
int main(){
    long long n,m,k,t,l=1<<30,r=0,i,u,v,dif,w,mid,temp,Min,power,price;
    scanf("%lld %lld %lld %lld",&n,&m,&k,&t);
    for(i=1;i<=m;i++){
        scanf("%lld %lld %lld %lld",&u,&v,&dif,&w);
        g[u].push_back({v,dif,w});
        g[v].push_back({u,dif,w});
    }
    l=1,r=100001;
    while(l<r){
        mid=(l+r)/2;
        for(i=2;i<=n;i++)dis[i]=1<<30;
        q.push({1,0});
        while(!q.empty()){
            u=q.top().u;
            w=q.top().w;
            q.pop();
            if(w>t)break;
            if(u==n){r=mid;goto jump;}
            for(auto x:g[u]){
                if(x.dif>mid)continue;
                if(dis[u]+x.w<=t && dis[x.u]>dis[u]+x.w){
                    if(x.u==n){r=mid;goto jump;}
                    dis[x.u]=dis[u]+x.w;
                    q.push({x.u,dis[x.u]});
                }
            }
        }
        l=mid+1;
        jump:;
        while(!q.empty())q.pop();
    }
    if(l==temp){printf("-1\n");return 0;}
    Min=1<<30;
    for(i=1;i<=k;i++){
        scanf("%lld %lld",&price,&power);
        if(power>=l)Min=min(Min,price);
    }
    if(Min==1<<30)printf("-1\n");
    else printf("%lld\n",Min);
    return 0;
}
/*
2 2 3 50
1 2 50 100
1 2 100 50
40 70
30 50
70 100
*/
