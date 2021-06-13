#include<bits/stdc++.h>
using namespace std;
long long dp[100100];
struct A{
    long long u,t,w;
    bool operator<(const A&o)const{
        return t>o.t;
    }
};
priority_queue<A>q;
long long p[100100];
long long fin(long long i){
    if(p[i]==i)return i;
    return fin(p[i]);
}
int main(){
    long long n,Q,i,opr,temp,u,v,w,t;
    scanf("%lld %lld",&n,&Q);
    for(i=1;i<=n;i++){
        scanf("%lld",&dp[i]);
        p[i]=i;
    }
    long long qq=1;
    while(Q--){
        while(!q.empty() && q.top().t<=qq){
            u=q.top().u;
            dp[fin(u)]+=q.top().w;
            q.pop();
        }
        scanf("%lld",&opr);
        if(opr==1){
            scanf("%lld",&u);
            temp=u;
            while(p[temp]!=temp){
                dp[p[temp]]-=dp[u];
                temp=p[temp];
            }
            p[u]=u;
        }
        if(opr==2){
            scanf("%lld %lld %lld %lld",&u,&v,&t,&w);
            if(u!=fin(v)){
                temp=u;
                while(p[temp]!=temp){
                    dp[p[temp]]-=dp[u];
                    temp=p[temp];
                }
                p[u]=fin(v);
                dp[fin(v)]+=dp[u];
                q.push({u,t,w});
            }
        }
        if(opr==3){
            scanf("%lld",&u);
            printf("%lld\n",dp[fin(u)]);
        }
        qq++;
    }
    return 0;
}
/*
7 10
1 2 3 4 5 6 7
3 1
2 1 2 5 3
*/
