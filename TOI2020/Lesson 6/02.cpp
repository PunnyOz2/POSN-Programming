#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v,w;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
priority_queue<A> q;
struct B{
    int w,price;
    bool operator<(const B&o)const{
        if(w!=o.w)return w<o.w;
        return price>o.price;
    }
};
B roof[1000100];
int p[3010];
int fin(int i){
    if(p[i]==i)return i;
    return p[i]=fin(p[i]);
}
int main(){
    int n,m,i,u,v,w,st,pu,pv,k,Min=1<<30,sum=0,l,r,mid;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)p[i]=i;
    for(i=1;i<=m;i++){
        scanf("%d %d %d %d",&u,&v,&w,&st);
        if(st==1){
            pu=fin(u);
            pv=fin(v);
            if(pu!=pv){
                p[pv]=pu;
            }
        }
        else{
            q.push({u,v,w});
        }
    }
    scanf("%d",&k);
    for(i=1;i<=k;i++){
        scanf("%d %d",&roof[i].w,&roof[i].price);
    }
    sort(roof+1,roof+k+1);
    for(i=k;i>=1;i--){
        Min=min(Min,roof[i].price);
        roof[i].price=Min;
    }
    while(!q.empty()){
        u=q.top().u;
        v=q.top().v;
        w=q.top().w;
        q.pop();
        pu=fin(u);
        pv=fin(v);
        if(pu!=pv){
            p[pv]=pu;
            l=1,r=k;
            while(l<r){
                mid=(l+r)/2;
                if(roof[mid].w>=w)r=mid;
                else l=mid+1;
            }
            sum+=roof[l].price;
        }
    }
    printf("%d\n",sum);
    return 0;
}
/*
6 8
0 1 19 0
1 2 50 1
1 3 5 0
2 3 18 0
0 4 32 0
3 4 22 0
2 5 70 0
4 5 20 1
8
5 60
50 200
75 350
20 100
40 145
15 50
35 150
8 60
*/
