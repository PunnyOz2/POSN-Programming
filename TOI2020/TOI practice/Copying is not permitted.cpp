#include<bits/stdc++.h>
using namespace std;
struct A{
    long long u,v,w;
    bool operator<(const A&o)const{
        return w<o.w;
    }
};
vector<A> a;
long long p[40100];
long long fin(long long i){
    if(p[i]==i)return i;
    return p[i]=fin(p[i]);
}
vector<pair<long long,long long>> c;
int main(){
    long long n,m,k,i,l,r,mid,u,v,w,pu,pv,ch;
    scanf("%lld %lld %lld",&n,&m,&k);
    for(i=1;i<=m;i++){
        scanf("%lld %lld %lld",&u,&v,&w);
        a.push_back({u,v,w});
    }
    for(i=1;i<=k;i++){
        scanf("%lld %lld",&u,&v);
        c.push_back({u,v});
    }
    sort(a.begin(),a.end());
    l=1;
    r=1<<30;
    while(l<r){
        ch=0;
        mid=(l+r)/2;
        for(i=1;i<=n;i++)p[i]=i;
        for(i=0;i<a.size();i++){
            if(a[i].w>=mid)break;
            u=a[i].u;
            v=a[i].v;
            w=a[i].w;
            pu=fin(u);
            pv=fin(v);
            if(pu!=pv){
                p[pv]=pu;
            }
        }
        for(auto x:c){
            if(fin(x.first)==fin(x.second)){ch=1;break;}
        }
        if(ch==1)r=mid;
        else l=mid+1;
    }
    if(l==1<<30)printf("-1\n");
    else printf("%lld\n",l-1);
    return 0;
}
/*
5 6 1
1 2 7
1 3 7
1 4 7
2 5 4
3 5 3
4 5 5
1 5
*/
