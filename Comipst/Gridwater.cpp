/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v,w,st;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
struct B{
    int u,w;
};
int LCA[20][200000];
int lv[200000];
priority_queue<A> q;
queue<A> q2;
vector<B> g[200000];
int Max;
int Maxedge[20][200000];
int p[200000];
void make(int u,int old,int level){
    lv[u]=level;
    for(auto x:g[u]){
        if(x.u==old) continue;
        make(x.u,u,level+1);
        LCA[0][x.u]=u;
        Maxedge[0][x.u]=x.w;
    }
}
int fin(int i){
    if(p[i]==i)return i;
    return p[i]=fin(p[i]);
}
void play(int a,int b){
    if(lv[a]<lv[b]){
        swap(a,b);
    }
    int i;
    for(i=18;i>=0;i--){
        if(lv[LCA[i][a]]>=lv[b])Max=max(Max,Maxedge[i][a]),a=LCA[i][a];
    }
    if(a==b)return;
    for(i=18;i>=0;i--){
        if(LCA[i][a]!=LCA[i][b])Max=max(Max,max(Maxedge[i][a],Maxedge[i][b])),a=LCA[i][a],b=LCA[i][b];
    }
    Max=max(Max,max(Maxedge[0][a],Maxedge[0][b]));
}
int main()
{
    int n,m,i,j,w,u,v,st,pu,pv,k;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            p[(i-1)*m+j]=(i-1)*m+j;
        }
    }
    for(i=1;i<n;i++){
        for(j=1;j<m;j++){
            scanf("%d",&w);
            q.push({(i-1)*m+j,(i-1)*m+j+1,w,0});
        }
        for(j=1;j<=m;j++){
            scanf("%d",&w);
            q.push({(i-1)*m+j,(i)*m+j,w,0});
        }
    }
    for(j=1;j<m;j++){
        scanf("%d",&w);
        q.push({(n-1)*m+j,(n-1)*m+j+1,w,0});
    }
    while(!q.empty()){
        u=q.top().u;
        v=q.top().v;
        w=q.top().w;
        st=q.top().st;
        pu=fin(u);
        pv=fin(v);
        if(pu!=pv){
            p[pv]=pu;
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }
        else{
            q2.push(q.top());
        }
        q.pop();
    }
    make(1,0,0);
    for(k=1;k<=18;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                LCA[k][(i-1)*m+j]=LCA[k-1][LCA[k-1][(i-1)*m+j]];
                Maxedge[k][(i-1)*m+j]=max(Maxedge[k-1][(i-1)*m+j],Maxedge[k-1][LCA[k-1][(i-1)*m+j]]);
            }
        }
    }
    int ans=1<<30;
    while(!q2.empty()){
        u=q2.front().u;
        v=q2.front().v;
        w=q2.front().w;
        st=q2.front().st;
        q2.pop();
        Max=0;
        play(u,v);
        //printf("%d %d %d\n",u,v,w);
        ans=min(ans,w-Max);
    }
    printf("%d\n",ans);
    return 0;
}
/*
4 5
1 80 7 200
90 2 11 16 55
3 8 30 100
96 60 40 12 56
20 50 10 300
140 5 13 302 57
70 4 15 301
*/
