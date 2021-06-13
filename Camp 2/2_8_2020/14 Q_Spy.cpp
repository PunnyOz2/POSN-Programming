#include <bits/stdc++.h>
using namespace std;
struct A{
    long long num,i,j;
    bool operator<(const A&o)const{
        return num>o.num;
    }
};
priority_queue<A> q;
long long p[1100];
long long fin(long long i){
    if(p[i]==i)return i;
    return p[i]=fin(p[i]);
}
int main(){
    long long n,anss=1<<30,i,j,num,flycost=0,pu,pv,ans=0;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%lld",&num);
            if(i<j)q.push({num,i,j});
        }
    }
    for(i=1;i<=n;i++){
        p[i]=i;
        scanf("%lld",&num);
        q.push({num,i,n+1});
    }
    p[n+1]=n+1;
    while(!q.empty()){
        i=q.top().i;
        j=q.top().j;
        num=q.top().num;
        q.pop();
        pu=fin(i);
        pv=fin(j);
        if(pu!=pv){
            p[pv]=pu;
            ans+=num;
        }
    }
    printf("%lld\n",ans);
}
/*
5
0 3 12 15 11
3 0 14 3 20
12 14 0 11 7
15 3 11 0 15
11 20 7 15 0
5 10 10 10 10
*/
