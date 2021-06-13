/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v;
    long long w;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
A a[1000100];
int p[3000];
int fin(int i){
    if(p[i]==i) return i;
    return p[i]=fin(p[i]);
}
int main()
{
    int n,m,s,b,i,pu,pv,q;
    long long Min=1000000000000,ans;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d %d %d",&a[i].u,&a[i].v,&a[i].w);
    }
    for(i=1;i<=n;i++) p[i]=i;
    sort(a,a+m);
    scanf("%d %d %d",&s,&b,&q);
    for(i=0;i<m;i++){
        pu=fin(a[i].u),pv=fin(a[i].v);
        if(pu!=pv){
            Min=min(a[i].w,Min);
            p[pv]=pu;
        }
        if(fin(s)==fin(b))break;
    }
    if(q%(Min-1)!=0) ans=q/(Min-1)+1;
    else ans=q/(Min-1);
    printf("%lld",ans);

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
