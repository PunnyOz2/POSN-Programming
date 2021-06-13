/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long in[400100],out[400100],se[3000000],cou,lazy[3000000],col[400100],u,v;
vector<long long> g[400100];
void dfs(long long u,long long old){
    in[u]=++cou;
    for(auto x:g[u]){
        if(x!=old)dfs(x,u);
    }
    out[u]=++cou;
}
void update(long long l,long long r,long long a,long long b,long long val,long long now){
    if(lazy[now]){
        if(l!=r)lazy[now*2]=lazy[now*2+1]=lazy[now];
        se[now]=1ll<<(lazy[now]-1);
        lazy[now]=0;
    }
    if(r<a||l>b)return;
    if(l>=a && r<=b){
        se[now]=1ll<<(val-1);
        if(l!=r)lazy[now*2]=lazy[now*2+1]=val;
        return;
    }
    long long mid=(l+r)/2;
    update(l,mid,a,b,val,now*2);
    update(mid+1,r,a,b,val,now*2+1);
    se[now]=se[now*2]|se[now*2+1];
}
long long query(long long l,long long r,long long a,long long b,long long now){
    if(lazy[now]){
        if(l!=r)lazy[now*2]=lazy[now*2+1]=lazy[now];
        se[now]=1ll<<(lazy[now]-1);
        lazy[now]=0;
    }
    if(r<a||l>b)return 0;
    if(l>=a && r<=b){
        return se[now];
    }
    long long mid=(l+r)/2;
    return query(l,mid,a,b,now*2)|query(mid+1,r,a,b,now*2+1);
}
void dfs2(long long u,long long old){
    update(1,cou,in[u],out[u],col[u],1);
    for(auto x:g[u]){
        if(x!=old)dfs2(x,u);
    }
}
int main()
{
    long long n,q,i,opr,color;
    scanf("%lld %lld",&n,&q);
    for(i=1;i<=n;i++){
        scanf("%lld",&col[i]);
    }
    for(i=1;i<=n-1;i++){
        scanf("%lld %lld",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    dfs2(1,0);
    while(q--){
        scanf("%lld",&opr);
        if(opr==1){
            scanf("%lld %lld",&u,&color);
            //printf("    %lld %lld\n",in[u],out[u]);
            update(1,cou,in[u],out[u],color,1);
        }
        if(opr==2){
            scanf("%lld",&u);
            //printf("    %lld %lld\n",in[u],out[u]);
            printf("%d\n",__builtin_popcountll(query(1,cou,in[u],out[u],1)));
        }
    }
    return 0;
}
/*
7 10
1 1 1 1 1 1 1
1 2
1 3
1 4
3 5
3 6
3 7

1 3 2
2 1
1 4 3
2 1
1 2 5
2 1
1 6 4
2 1
2 2
2 3
*/
