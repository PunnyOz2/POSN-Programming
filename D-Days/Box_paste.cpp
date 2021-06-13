/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long w,l,h;
    bool operator<(const A&o)const {
        if(w!=o.w)return w<o.w;
        return l<o.l;
    }
};
vector<A> g;
long long a[4010][3],dis[30000];
int main()
{
    long long n,i,j,ma=0;
    scanf("%lld",&n);
    for(i=0;i<n;i++){
        scanf("%lld %lld %lld",&a[i][0],&a[i][1],&a[i][2]);
    }
    for(i=0;i<n;i++){
        g.push_back({a[i][0],a[i][1],a[i][2]});
        g.push_back({a[i][1],a[i][2],a[i][0]});
        g.push_back({a[i][0],a[i][2],a[i][1]});
        g.push_back({a[i][2],a[i][1],a[i][0]});
        g.push_back({a[i][2],a[i][0],a[i][1]});
        g.push_back({a[i][1],a[i][0],a[i][2]});
    }
    sort(g.begin(),g.end());
    for(i=0;i<g.size();i++){
        dis[i]=g[i].h;
        for(j=i-1;j>=0;j--){
            if(g[j].w<g[i].w && g[j].l<g[i].l)dis[i]=max(dis[i],dis[j]+g[i].h);
        }
        ma=max(ma,dis[i]);
    }
    printf("%lld\n",ma);
    return 0;
}
/*
5
4 2 3
1 4 1
2 3 5
2 3 3
1 5 4

2
3 2 5
4 2 1
*/
