#include<bits/stdc++.h>
using namespace std;
struct A{
    int x,y,id;
};
bool cmpbyx(A a,A b){
    return a.x<b.x;
}
bool cmpbyy(A a,A b){
    return a.y<b.y;
}
int p[100100];
A a[100100];
int fin(int i){
    if(p[i]==i)return i;
    return p[i]=fin(p[i]);
}
int main(){
    int q,n,cou,i,pu,pv;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        cou=n;
        for(i=1;i<=n;i++)scanf("%d %d",&a[i].x,&a[i].y),a[i].id=i,p[i]=i;
        sort(a+1,a+n+1,cmpbyx);
        for(i=1;i<n;i++){
            if(a[i].x==a[i+1].x){
                pu=fin(a[i].id);
                pv=fin(a[i+1].id);
                if(pu!=pv){
                    p[pu]=pv;
                    cou--;
                }
            }
        }
        sort(a+1,a+n+1,cmpbyy);
        for(i=1;i<n;i++){
            if(a[i].y==a[i+1].y){
                pu=fin(a[i].id);
                pv=fin(a[i+1].id);
                if(pu!=pv){
                    p[pu]=pv;
                    cou--;
                }
            }
        }
        printf("%d\n",cou/2+cou%2);
    }
    return 0;
}
/*
2
4
1 2
2 1
2 3
3 2
9
2 1
1 2
2 3
2 5
1 6
2 7
4 3
5 4
4 5
*/
