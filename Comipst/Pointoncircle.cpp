/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
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
struct B{
    int u,w;
};
vector<B> g[1010];
priority_queue<A> q;
int p[1010],in[1010],ans[1010];
int fin(int i){
    if(p[i]==i)return i;
    return p[i]=fin(p[i]);
}
int main()
{
    int n,k,i,j,w,dis,u,v,pu,pv,old,ch;
    scanf("%d %d",&n,&k);
    for(i=1;i<=k;i++){
        p[i]=i;
        for(j=1;j<=k;j++){
            scanf("%d",&w);
            q.push({i,j,w});
        }
    }
    while(!q.empty()){
        u=q.top().u;
        v=q.top().v;
        w=q.top().w;
        pu=fin(u);
        pv=fin(v);
        q.pop();
        if(pu!=pv){
            g[u].push_back({v,w});
            g[v].push_back({u,w});
            //printf("%d %d %d\n",u,v,w);
            in[u]++;
            in[v]++;
            p[pv]=pu;
        }
    }
    for(i=1;i<=k;i++){
        if(in[i]==1)break;
    }
    u=i,old=0,dis=0;
    int first=i;
    ans[u]=0;
    //printf("%d\n",u);
    for(i=1;i<k;i++){
        //ch=0;
        for(auto x:g[u]){
            if(x.u!=first && x.u!=old){
                ans[x.u]=ans[u]+x.w;
                old=u;
                u=x.u;
                break;
                //printf("%d %d\n",x.u,ans[x.u]);
            }
        }
        //if(ch==0)break;
    }
    for(i=1;i<=k;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}
