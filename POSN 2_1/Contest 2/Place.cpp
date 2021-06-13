/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long u,v,w;
    bool operator<(const A&o)const{
        return w<o.w;
    }
};
priority_queue<A> q;
long long p[230000];
int fin(int i){
    if(p[i]==i)return i;
    return p[i]=fin(p[i]);
}
int main()
{
	long long n,m,i,u,v,pu,pv,w;
	scanf("%lld %lld",&n,&m);
	for(i=0;i<m;i++){
	    scanf("%lld %lld %lld",&u,&v,&w);
        q.push({u,v,w});
	}
	long long sum=0;
	for(i=1;i<=n;i++)p[i]=i;
	while(!q.empty()){
        u=q.top().u,v=q.top().v,w=q.top().w;
        q.pop();
        pu=fin(u),pv=fin(v);
        if(pu!=pv){
            sum+=(w-1);
            p[pu]=pv;
        }
	}
	printf("%lld\n",sum);
    return 0;
}
/*
6 9
1 2 8
2 3 6
1 4 6
4 2 6
4 5 8
2 5 7
5 6 5
2 6 9
3 6 5
*/
