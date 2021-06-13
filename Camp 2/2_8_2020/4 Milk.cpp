#include <bits/stdc++.h>
using namespace std;
int p[100100];
int fin(int i){
    if(p[i]==i)return i;
    return p[i]=fin(p[i]);
}
int main(){
    int n,q,i,a,b,pu,pv;
    char com;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++){
        p[i]=i;
    }
    while(q--){
        scanf(" %c",&com);
        if(com=='q'){
            scanf("%d %d",&a,&b);
            pu=fin(a);
            pv=fin(b);
            if(p[pu]==p[pv])printf("yes\n");
            else printf("no\n");
        }
        else{
            scanf("%d %d",&a,&b);
            pu=fin(a);
            pv=fin(b);
            if(pu!=pv){
                p[pu]=pv;
            }
        }
    }
}
/*
5 10 q 1 2 c 1 3 q 3 2 c 3 2 q 1 2 q 4 5
*/
