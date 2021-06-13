/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v;
    float w;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
priority_queue<A> q;
int p[100100];
int fin(int i){
    if(p[i]==i) return i;
    return p[i]=fin(p[i]);
}
int main()
{
	int n,m,i,u,v,pu,pv;
	float w,sum;
	scanf("%d %d",&n,&m);
	for(i=0;i<=n;i++)p[i]=i;
	while(m--){
        scanf("%d %d %f",&u,&v,&w);
        q.push({u,v,w});
	}
	sum=0;
	while(!q.empty()){
        u=q.top().u,v=q.top().v,w=q.top().w,q.pop();
        pu=fin(u),pv=fin(v);
        if(pu!=pv){
            sum+=w;
            p[pv]=pu;
        }
	}
	printf("%.3f",sum);
    return 0;
}
