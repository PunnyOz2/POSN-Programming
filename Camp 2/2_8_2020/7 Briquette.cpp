#include <bits/stdc++.h>
using namespace std;
int p[100100],mark[100100],mark2[100100];
int fin(int i){
    if(p[i]==i)return i;
    return p[i]=fin(p[i]);
}
int main(){
    int n,m,cou,i,j,num,a,b,pu,pv;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++){
        p[i]=i;
    }
    cou=0;
    for(i=1;i<=n;i++){
        scanf("%d",&num);
        if(num==0){cou++;continue;}
        scanf("%d",&a);
        pu=fin(a);
        mark2[a]=1;
        for(j=2;j<=num;j++){
            scanf("%d",&b);
            mark2[b]=1;
            pv=fin(b);
            if(pu!=pv){
                p[pv]=pu;
            }
        }
    }
    for(i=1;i<=m;i++){
        pu=fin(i);
        if(mark[pu]==0 && mark2[pu]==1){
            cou++;
            mark[pu]=1;
        }
    }
    printf("%d\n",cou-1);
}
/*
8 7
0
3 1 2 3
1 1
2 5 4
2 6 7
1 3
2 7 4
1 1
*/
