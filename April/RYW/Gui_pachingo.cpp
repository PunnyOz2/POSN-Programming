/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long now,ma;
    bool operator<(const A&o)const{
        return ma>o.ma;
    }
};
priority_queue<A> h;
queue<int> q;
vector<int> g[100100],gltor[100100],g2[100100];
long long degin[100100];
long long dp[100100],qs[100100];
long long si;
long long ans[100100];
void dfs(long long now){
    for(auto x:g2[now]){
        dfs(x);
    }
    ans[si++]=now;
}
int main()
{
	long long n,m,i,u,v;
	scanf("%lld %lld",&n,&m);
	for(i=1;i<=n;i++){
        scanf("%lld",&u);
        g[u].push_back(i);
        gltor[i].push_back(u);
        degin[u]++;
	}
	for(i=1;i<=n;i++){
        if(g[i].size()==0){
            q.push(i);
        }
	}
    while(!q.empty()){
        u=q.front();
        q.pop();
        dp[u]=u;
        for(auto x:g[u]){
            dp[u]=max(dp[u],dp[x]);
        }
        for(auto x:gltor[u]){
            degin[x]--;
            if(degin[x]==0)
                q.push(x);
        }
    }
	h.push({g[0][0],0});
	long long k;
	A so[100100];
	while(!h.empty()){
        u=h.top().now;
        h.pop();
        k=0;
        for(auto x:g[u]){
            so[k].now = x;
            so[k].ma = dp[x]*-1;
            k++;
        }
        sort(so,so+k);
        for(i=0;i<k;i++){
            g2[u].push_back(so[i].now);
            h.push({so[i].now,so[i].ma*-1});
        }
	}
	si=1;
	dfs(g[0][0]);
	for(i=1;i<si;i++){
        qs[i]=ans[i]+qs[i-1];
	}
	long long opr;
	k=0;
	while(m--){
        scanf("%lld",&opr);
        if(opr==1){
            scanf("%lld",&i);
            k+=i;
            printf("%lld\n",ans[k]);
        }
        if(opr==2){
            scanf("%lld",&i);
            k-=i;
        }
        if(opr==3){
            printf("%lld\n",qs[k]);
        }
	}
    return 0;
}
/*
7 5
7
7
5
0
4
4
4
1 3
1 1
3
1 3
3
*/
