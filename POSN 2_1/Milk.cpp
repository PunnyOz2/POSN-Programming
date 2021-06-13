/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int p[100100];
int fin(int i){
    if(p[i]==i) return i;
    return p[i]=fin(p[i]);
}
int main()
{
	int n,q,u,v,i,pu,pv;
	char Q;
	scanf("%d %d",&n,&q);
	for(i=1;i<=n;i++)p[i]=i;
	while(q--){
        scanf(" %c",&Q);
        scanf("%d %d",&u,&v);
        pu=fin(u),pv=fin(v);
        if(Q=='c'){
            if(pu!=pv){
                p[pu]=pv;
            }
        }
        if(Q=='q'){
            if(pu==pv)printf("yes\n");
            else printf("no\n");
        }
	}
    return 0;
}
