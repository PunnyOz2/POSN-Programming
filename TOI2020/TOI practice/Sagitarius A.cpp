#include<bits/stdc++.h>
using namespace std;
struct A{
    long long u,v,w,i;
    bool operator<(const A&o)const{
        return w<o.w;
    }
};
priority_queue<A> q;
long long p[100100];
long long fin(long long i){
    if(p[i]==i)return i;
    return p[i]=fin(p[i]);
}
vector<long long> ans;
int main(){
    long long n,m,i,u,v,w,pu,pv,t,Max,temp,cou;
    long long sum;
    scanf("%lld %lld",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%lld %lld %lld",&u,&v,&w);
        q.push({u,v,w,i});
    }
    for(i=1;i<=n;i++)p[i]=i;
    sum=0;
    scanf("%lld",&t);
    Max=-1;
    cou=0;
    while(!q.empty()){
        u=q.top().u;
        v=q.top().v;
        w=q.top().w;
        i=q.top().i;
        q.pop();
        pu=fin(u);
        pv=fin(v);
        if(pu!=pv){
            ans.push_back(i);
            p[pv]=pu;
            sum+=w;
            cou++;
        }
        else{
            if(Max<w){
                Max=w;
                temp=i;
            }
        }
    }
    if(m<n){printf("-1\n");return 0;}
    for(i=1;i<n;i++){
        if(fin(i)!=fin(i+1)){printf("-1\n");return 0;}
    }
    printf("%lld\n",sum+Max);
    if(t==2){
        if(cou<n)ans.push_back(temp);
        sort(ans.begin(),ans.end());
        for(auto x:ans)printf("%lld ",x);
    }
    return 0;
}
/*

*/
