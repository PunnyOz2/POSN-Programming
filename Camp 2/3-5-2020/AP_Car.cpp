/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j;
    bool operator<(const A&o)const{
        if(j!=o.j)return j<o.j;
        return i<o.j;
    }
};
A a[100100];
int main()
{
    int q,n,t,i,ii,jj,cou;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&t);
        for(i=1;i<=n;i++){
            scanf("%d %d",&a[i].i,&a[i].j);
            a[i].j*=t;
            a[i].j+=a[i].i;
        }
        sort(a+1,a+1+n);
        jj=a[n].j;
        ii=a[n].i;
        cou=n;
//        for(i=1;i<=n;i++){
//            printf("%d %d\n",a[i].i,a[i].j);
//        }
//        printf("Hi\n");
        for(i=n-1;i>=1;i--){
            if((ii<a[i].i && a[i].j<=jj) || (ii<=a[i].i && a[i].j<jj))cou--;
            else if(a[i].i<ii || a[i].j<ii){
                ii=a[i].i;
                jj=a[i].j;
            }
        }
        printf("%d\n",cou);
    }
    return 0;
}
/*

*/
