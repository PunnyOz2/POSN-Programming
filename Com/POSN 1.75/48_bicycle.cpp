/*
    TASK: AP_SHARK
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> mp;
struct A{
    int u,v,w;
    bool operator<(const A&o) const{
        return w>o.w;
    }
};
A edge[71000];
int p[51000];
int fin(int i){
    if(p[i]==i) return i;
    else return p[i]=fin(p[i]);
}
int main()
{
    int q,n,m,i,num,ans,u,v,w;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++){
            scanf("%d",&num);
            mp[num]=i,p[i]=i;
        }
        for(i=0,ans=0;i<m;i++){
            scanf("%d %d %d",&u,&v,&w);
            edge[i]={mp[u],mp[v],w};
            ans+=w;
        }
        sort(edge,edge+m);
        for(i=0;i<m;i++){
            if(p[fin(edge[i].u)]!=p[fin(edge[i].v)]){
                ans-=edge[i].w;
                p[fin(edge[i].u)]=fin(edge[i].v);
            }
        }
        printf("%d\n",ans);
        mp.clear();
    }
    return 0;
}
/*
2 8 10 1 2 3 4 5 6 7 8 1 2 3 1 5 5 2 3 4 2 6 3
3 4 2 3 7 5 4 8 5 5 6 2 6 7 7 7 8 3 14 18 5 11 13
0 3 8 6 2 12 14 1 9 10 4 5 0 2 5 6 7 5 10 7 11 6 5
11 10 9 11 12 4 13 14 3 13 8 5 13 12 6 0 1 7 3 2 7
3 8 1 3 4 1 8 9 1 6 1 7 2 1 9 14 9 1 9 4 3

*/
