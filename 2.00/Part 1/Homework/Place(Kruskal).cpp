/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v,w;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
A a[1000100];
int p[200100];
int fin(int i){
    if(p[i]==i) return i;
    return p[i]=fin(p[i]);
}
int main()
{
    int n,m,i,pu,pv;
    long long ans=0;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d %d %d",&a[i].u,&a[i].v,&a[i].w);
    }
    for(i=1;i<=n;i++) p[i]=i;
    sort(a,a+m);
    for(i=0;i<m;i++){
        pu=fin(a[i].u),pv=fin(a[i].v);
        //printf("a%d %d  ",pu,pv);
        if(pu!=pv){
            ans+=(a[i].w-1);
            p[pv]=pu;
        }
        //printf("b%d %d\n",p[a[i].u],p[a[i].v]);
    }
    printf("%lld",ans);

    return 0;
}
/*
6 9
1 2 8
2 3 6
1 4 6
4 2 6
4 5 8
2 5 7
5 6 5
2 6 9
3 6 5
*/
