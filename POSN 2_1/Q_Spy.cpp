/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,w;
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
    int n,i,j,pu,pv,u,v,sum,w;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&w);
            if(w!=0) q.push({i,j,w});
        }
    }
    for(i=0;i<n;i++)scanf("%d",&w),q.push({i,n,w});
    for(i=0;i<=n;i++)p[i]=i;
    sum=0;
    while(!q.empty()){
        u=q.top().i,v=q.top().j,w=q.top().w,q.pop();
        pu=fin(u),pv=fin(v);
        if(pu!=pv){
            p[pv]=pu;
            sum+=w;
        }
    }
	printf("%d",sum);
    return 0;
}
