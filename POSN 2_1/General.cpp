/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int p[100100],a[100100];
int fin(int i){
    if(p[i]==i) return i;
    return p[i]=fin(p[i]);
}
int main()
{
	int n,q,i,u,v,pu,pv;
	scanf("%d %d",&n,&q);
	for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        p[i]=i;
	}
	while(q--){
        scanf("%d %d",&u,&v);
        pu=fin(u),pv=fin(v);
        if(pu!=pv){
            if(a[pu]>a[pv]){
                p[pv]=pu;
                a[pu]+=a[pv]/2;
                printf("%d\n",pu);
            }
            else if(a[pu]<a[pv])p[pu]=pv,a[pv]+=a[pu]/2,printf("%d\n",pv);
            else if(pu<pv)p[pv]=pu,a[pu]+=a[pv]/2,printf("%d\n",pu);
            else p[pu]=pv,a[pv]+=a[pu]/2,printf("%d\n",pv);
        }
        else printf("-1\n");
	}
    return 0;
}
