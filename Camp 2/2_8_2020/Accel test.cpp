#include <bits/stdc++.h>
using namespace std;
struct A{
    int a,b;
    int c;
    bool operator<(const A&o)const{
        return c>o.c;
    }
};
priority_queue<A> q;
int p[100100];
int fin(int i){
    if(p[i]==i)return i;
    return p[i]=fin(p[i]);
}
struct B{
    int x,y,z,idx;
};
B a[100100];
bool comparex(B a,B b){
    return a.x<b.x;
}
bool comparey(B a,B b){
    return a.y<b.y;
}
bool comparez(B a,B b){
    return a.z<b.z;
}
int main(){
    int n,i,pu,pv,ans=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].z);
        a[i].idx=i;
        p[i]=i;
    }
    sort(a+1,a+n+1,comparex);
    for(i=1;i<n;i++){
        q.push({a[i].idx,a[i+1].idx,a[i+1].x-a[i].x});
    }
    sort(a+1,a+n+1,comparey);
    for(i=1;i<n;i++){
        q.push({a[i].idx,a[i+1].idx,a[i+1].y-a[i].y});
    }
    sort(a+1,a+n+1,comparez);
    for(i=1;i<n;i++){
        q.push({a[i].idx,a[i+1].idx,a[i+1].z-a[i].z});
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
    printf("%d\n",ans);
}
/*
3
-3 -3 -3
1 5 10
7 8 2
*/
