/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long dis[200];
struct A{
    long long u,w;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
priority_queue<A>q;
vector<A> g[200];
int main()
{
    long long n,w,i,u,Min,idx;
    char a,b;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf(" %c %c %lld",&a,&b,&w);
        g[a].push_back({b,w});
        g[b].push_back({a,w});
    }
    for(i=1;i<=150;i++){
        dis[i]=1<<30;
    }
    dis['Z']=0;
    q.push({'Z',0});
    while(!q.empty()){
        u=q.top().u;
        w=q.top().w;
//        printf("%c ",u);
//        printf("%lld\n",w);
        q.pop();
        for(auto x:g[u]){
            if(dis[x.u]>dis[u]+x.w){
                dis[x.u]=dis[u]+x.w;
                q.push({x.u,dis[x.u]});
            }
        }
    }
    Min=1<<30;
    for(i=65;i<=89;i++){
        if(Min>dis[i]){
            Min=dis[i];
            idx=i;
        }
    }
    printf("%c ",idx);
    printf("%lld\n",Min);
    return 0;
}
/*
5
A d 6
B d 3
C e 9
d Z 8
e Z 3
*/
