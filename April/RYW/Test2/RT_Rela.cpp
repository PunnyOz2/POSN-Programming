/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v,w;
    bool operator<(const A&o)const {
        return w<o.w;
    }
};
int p[4010];
int fin(int i){
    if(p[i]==i)return i;
    return p[i]=fin(p[i]);
}
priority_queue<A> h;
vector<A> g;
int a[4010];
int main()
{
	int n,m,q,check,i,pu,pv,u,v,w;
	scanf("%d %d %d",&n,&m,&q);
	for(i=1;i<=n;i++)p[i]=i;
	for(i=0;i<m;i++){
        scanf("%d %d %d",&u,&v,&w);
        g.push_back({u,v,w});
	}
	i=0;
	sort(g.begin(),g.end());
	for(auto x:g){
        u=x.u,v=x.v,w=x.w;
        pu=fin(u),pv=fin(v);
        if(pu!=pv){
            p[pu]=pv;
            a[i++]=w;
        }
	}
	while(q--){
        scanf("%d",&check);
        printf("%d\n",n-(upper_bound(a,a+i,check)-a));
	}
    return 0;
}
/*
5 6 2
1 2 7
1 3 7
1 4 7
2 5 4
3 5 3
4 5 5
*/
