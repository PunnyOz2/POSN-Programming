#include <bits/stdc++.h>
using namespace std;
struct A{
    long long u,v,dis;
    bool operator<(const A&o)const{
        return dis<o.dis;
    }
};
priority_queue<A> q;
long long p[70100];
long long fin(long long i){
    if(p[i]==i)return i;
    return p[i]=fin(p[i]);
}
map<long long,long long>mp;
int main(){
    long long n,m,Q,i,num,a,b,c,u,v,pu,pv,ans=0;
    scanf("%lld",&Q);
    while(Q--){
        scanf("%lld %lld",&n,&m);
        for(i=1;i<=n;i++){
            scanf("%lld",&num);
            mp[num]=i;
            p[i]=i;
        }
        for(i=1;i<=m;i++){
            scanf("%lld %lld %lld",&a,&b,&c);
            q.push({mp[a],mp[b],c});
        }
        while(!q.empty()){
            u=q.top().u;
            v=q.top().v;
            pu=fin(u);
            pv=fin(v);
            if(pu==pv){
                ans+=q.top().dis;
            }
            if(pu!=pv){
                p[pu]=pv;
            }
            q.pop();
        }
        printf("%lld\n",ans);
        ans=0;
        mp.clear();
    }
}
/*
2
14 18
5 11 13 0 3 8 6 2 12 14 1 9 10 4
5 0 2
5 6 7
5 10 7
11 6 5
11 10 9
11 12 4
13 14 3
13 8 5
13 12 6
0 1 7
3 2 7
3 8 1
3 4 1
8 9 1
6 1 7
2 1 9
14 9 1
9 4 3
8 10
1 2 3 4 5 6 7 8
1 2 3
1 5 5
2 3 4
2 6 3
3 4 2
3 7 5
4 8 5
5 6 2
6 7 7
7 8 3
*/
