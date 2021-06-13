#include <bits/stdc++.h>
using namespace std;
int p[100100];
int fin(int i){
    if(p[i]==i)return i;
    return p[i]=fin(p[i]);
}
int main(){
    int n,q,i,a,b,pu,pv,m;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        p[i]=i;
    }
    for(i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        pu=fin(a);
        pv=fin(b);
        if(pu!=pv){
            p[pu]=pv;
        }
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&a,&b);
        pu=fin(a);
        pv=fin(b);
        if(pu==pv)printf("YES\n");
        else{
            printf("NO\n");
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
