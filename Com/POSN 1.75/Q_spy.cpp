/*
    TASK: Q_spy
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v,w;
    bool operator< (const A&o) const{
        return w<o.w;
    }
};
A edge[1002000];
int p[1010];
int fin(int i){
    if(p[i]==i) return i;
    return p[i]=fin(p[i]);
}
int main()
{
    int i,j,n,w,cnt=0,ans=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&w);
            edge[cnt++]={i,j,w};
        }
    }
    for(i=1;i<=n;i++){
        scanf("%d",&w);
        edge[cnt++]={i,n+1,w};
    }
    sort(edge,edge+cnt);
    for(i=1;i<=n+1;i++) p[i]=i;
    for(i=0;i<cnt;i++){
        if(fin(edge[i].u)!=fin(edge[i].v))
            ans+=edge[i].w,p[fin(edge[i].u)]=fin(edge[i].v);
    }
    printf("%d\n",ans);
    return 0;
}
/*
3
0 6 9
6 0 4
9 4 0
7 7 7
*/
