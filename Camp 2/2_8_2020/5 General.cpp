#include <bits/stdc++.h>
using namespace std;
int p[100100];
int fin(int i){
    if(p[i]==i)return i;
    return p[i]=fin(p[i]);
}
int aa[100100];
int main(){
    int n,q,i,a,b,pu,pv;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++){
        scanf("%d",&aa[i]);
        p[i]=i;
    }
    while(q--){
        scanf("%d %d",&a,&b);
        if(a>b)swap(a,b);
        pu=fin(a);
        pv=fin(b);
        if(pu==pv)printf("-1\n");
        else{
            if(aa[pu]>=aa[pv]){
                aa[pu]+=aa[pv]/2;
                p[pv]=pu;
                printf("%d\n",pu);
            }
            else{
                aa[pv]+=aa[pu]/2;
                p[pu]=pv;
                printf("%d\n",pv);
            }
        }
    }
}
/*
5 4
3 4 5 6 7
1 5
1 2
1 2
*/
