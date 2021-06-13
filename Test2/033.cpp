//Tawatwee
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v,w,st,idx;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
struct B{
    int u,w;
};
int state=0;
struct C{
    int Max,w,idx;
    bool operator<(const C&o)const{
        if(state==0)return w<o.w;
        else return Max<o.Max;
    }
};
vector<B> g[100100];
int u,v,w,i,dis[100100],another;
C a[120000];
priority_queue<A> q,q2;
vector<A> out;
int LCA[30][100100],Maxed[30][100100],level[100100],p[100100];
void dfs(int u,int old,int lev){
    for(auto x:g[u]){
        if(x.u!=old){
            LCA[0][x.u]=u;
            Maxed[0][x.u]=x.w;
            level[x.u]=lev;
            dfs(x.u,u,lev+1);
        }
    }
}
int fin(int i){
    if(p[i]==i)return i;
    return p[i]=fin(p[i]);
}
int LC(int a,int b){
    int Max=0;
    if(level[a]<level[b])swap(a,b);
    for(i=20;i>=0;i--){
        if(level[LCA[i][a]]>=level[b])Max=max(Max,Maxed[i][a]),a=LCA[i][a];
    }
    if(a==b)return Max;
    for(i=20;i>=0;i--){
        if(LCA[i][a]!=LCA[i][b])Max=max(Max,max(Maxed[i][a],Maxed[i][b])),a=LCA[i][a],b=LCA[i][b];
    }
    Max=max(Max,max(Maxed[0][a],Maxed[0][b]));
    return Max;
}
int ans[220000];
int main()
{
    int n,m,pu,pv,st,j,Max=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n-1;i++){
        scanf("%d %d %d",&u,&v,&w);
        q.push({u,v,w,1,i});
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(i=n;i<=m;i++){
        scanf("%d %d %d",&u,&v,&w);
        q.push({u,v,w,0,i});
        ans[i]=w;
    }
    for(i=1;i<=n;i++){
        p[i]=i;
    }
    level[1]=1;
    dfs(1,0,1);
    for(i=1;i<=n;i++){
        for(j=1;j<=20;j++){
            LCA[j][i]=LCA[j-1][LCA[j-1][i]];
            Maxed[j][i]=max(Maxed[j-1][LCA[j-1][i]],Maxed[j-1][i]);
        }
    }
    while(!q.empty()){
        u=q.top().u;
        v=q.top().v;
        w=q.top().w;
        st=q.top().st;
        i=q.top().idx;
        pu=fin(u);
        pv=fin(v);
        q.pop();
        if(pu!=pv){
            if(st==0){
                q2.push({u,v,w,st,i});
            }
            else{
                p[pv]=pu;
            }
        }
        else if(st==0){
            out.push_back({u,v,w,st,i});
        }
    }
    int i=0,pote,pote2,pote3,temp;
    int mid,l,r,idx;
    //printf("Hi\n");
    while(!q2.empty()){
        u=q2.top().u;
        v=q2.top().v;
        w=q2.top().w;
        st=q2.top().st;
        idx=q2.top().idx;
        q2.pop();
        Max=LC(u,v);
        i=0;
        pote=pote2=1<<30;
        pote3=-1;
        //printf(" %d %d %d %d\n",u,v,Max,w);
        for(auto x:out){
                //printf("   %d %d\n",LC(x.u,x.v),x.w);
            if(LC(x.u,x.v)<=w &&Max<=x.w){
                if(pote>x.w){
                    pote=x.w;
                    pote2=x.idx;
                    pote3=i;
                }
            }
            i++;
        }
                //printf("%d %d %d\n",pote,pote2,pote3);
        if(pote3==-1){
            printf("0\n");
            return 0;
        }
        out[pote3].w=w;
        temp=ans[idx];
        ans[idx]=ans[pote2];
        ans[pote2]=temp;
        out.push_back({u,v,ans[idx],st,idx});
    }
    printf("1\n");
    for(i=n;i<=m;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}
/*
5 7
1 2 1
1 4 2
1 5 9
2 3 6
4 2 10
4 3 3
5 3 7
*/
