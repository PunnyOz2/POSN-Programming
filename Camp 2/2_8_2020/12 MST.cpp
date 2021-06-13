#include <bits/stdc++.h>
using namespace std;
struct A{
    int a,b;
    double c;
    bool operator<(const A&o)const{
        return c>o.c;
    }
};
priority_queue<A> q;
int p[10100];
int fin(int i){
    if(p[i]==i)return i;
    return p[i]=fin(p[i]);
}
int main(){
    int n,m,i,pu,pv;
    int a,b;
    double c,ans;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d %d %lf",&a,&b,&c);
        q.push({a,b,c});
    }
    for(i=0;i<=n;i++){
        p[i]=i;
    }
    while(!q.empty()){
        pu=fin(q.top().a);
        pv=fin(q.top().b);
        if(pu!=pv){
            p[pu]=pv;
            ans+=q.top().c;
        }
        q.pop();
    }
    printf("%.3lf\n",ans);
}
/*
4 4
0 1 1 1 2 1 2 3 1 3 0 2
*/
