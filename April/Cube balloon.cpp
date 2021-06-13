#include<bits/stdc++.h>
using namespace std;
long long dp[100100],p[100100];
long long fin(long long i){
    if(p[i]==i)return i;
    return fin(p[i]);
}
struct A{
    long long v,target,t;
    bool operator<(const A&o)const{
        return t>o.t;
    }
};
priority_queue<A> q;
int main()
{
	long long n,Q,opr,node,i,target,v,t,tmp;
	scanf("%lld %lld",&n,&Q);
	for(i=1;i<=n;i++)p[i]=i,scanf("%lld",&dp[i]);
	for(i=1;i<=Q;i++){
        scanf("%lld",&opr);
        while(!q.empty() && q.top().t<=i){
            target=q.top().target;
            v=q.top().v;
            q.pop();
            dp[fin(target)]+=v;
        }
        if(opr==1){
            scanf("%lld",&node);
            tmp=node;
            while(p[tmp]!=tmp)
                dp[p[tmp]]-=dp[node],tmp=p[tmp];
            p[node]=node;
        }
        if(opr==2){
            scanf("%lld %lld %lld %lld",&node,&target,&t,&v);
            if(node!=fin(target)){
                tmp=node;
                while(p[tmp]!=tmp)
                    dp[p[tmp]]-=dp[node],tmp=p[tmp];
                tmp=fin(target);
                p[node]=tmp;
                dp[tmp]+=dp[node];
                q.push({v,node,t});
            }
        }
        if(opr==3){
            scanf("%lld",&node);
            printf("%lld\n",dp[fin(node)]);
        }
	}
    return 0;
}
/*
7 10
1 2 3 4 5 6 7
3 1
2 1 2 5 3
3 1
3 2
3 2
1 1
3 2
2 2 3 9 4
3 2
3 3
*/
