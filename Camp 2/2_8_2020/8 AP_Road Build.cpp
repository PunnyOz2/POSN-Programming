#include <bits/stdc++.h>
using namespace std;
pair<int,int> citypair[250100];
struct A{
    int u,v;
};
A a[250100];
int p[300100];
int fin(int i){
    if(p[i]==i)return i;
    return p[i]=fin(p[i]);
}
int main(){
    int t,v,e,m,l,r,mid,aa,b,i,pu,pv,mark;
    int cou=0;
    scanf("%d",&t);
    while(t--){
        cou++;
        scanf("%d %d %d",&v,&e,&m);
        for(i=1;i<=m;i++){
            scanf("%d %d",&aa,&b);
            citypair[i]={aa,b};
        }
        for(i=1;i<=e;i++){
            scanf("%d %d",&a[i].u,&a[i].v);
        }
        l=1;
        r=e+1;
        while(l<r){
            mid=(l+r)/2;
//            printf("  %d\n",mid);
            for(i=1;i<=v;i++){
                p[i]=i;
            }
            for(i=1;i<=mid;i++){
//                    printf("     %d %d\n",a[i].u,a[i].v);
                pu=fin(a[i].u);
                pv=fin(a[i].v);
                if(pu!=pv){
                    p[pu]=pv;
                }
            }
            mark=0;
            for(i=1;i<=m;i++){
//                printf("             %d %d\n",citypair[i].first,citypair[i].second);
//                printf("             %d %d\n",fin(citypair[i].first),fin(citypair[i].second));
                if(fin(citypair[i].first)!=fin(citypair[i].second)){mark=1;break;}
            }
            if(mark==1)l=mid+1;
            else r=mid;
        }
        if(l==e+1)printf("C#%d: -1\n",cou);
        else printf("C#%d: %d\n",cou,l);
    }
}
/*
1
5 5 5
1 2
1 3
3 2
4 5
2 5

1 5
2 3
1 4
1 3
2 5
*/
