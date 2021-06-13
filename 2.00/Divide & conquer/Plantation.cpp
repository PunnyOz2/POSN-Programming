/*
    TASK: Plantation
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
#define MAXD 2000000000
struct A{
    int x,y;
};
A a[100100];
bool cmpbyx(A a,A b){
    return a.x<b.x;
}
bool cmpbyy(A a,A b){
    return a.y<b.y;
}
double dist(A a,A b){
    return sqrt(1.0*(a.x-b.x)*(a.x-b.x)+1.0*(a.y-b.y)*(a.y-b.y));
}
double closest(A b[],int n){
    int i,j,mid,k;
    double mi=MAXD,dl,dr,d,o;
    if(n<=3){
        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++)
                mi=min(mi,dist(b[i],b[j]));
        return mi;
    }
    mid =n/2;
    A temp = b[mid];
    dl=closest(b,mid);
    dr=closest(b+mid,n-mid);
    d=min(dl,dr);
    A strip[n+2],midp=b[mid];
    for(i=0,j=0;i<n;i++){
        if(abs(b[i].x-midp.x)<d)
            strip[j++]=b[i];
    }
    sort(strip,strip+j,cmpbyy);
    o=d;
    for(i=0;i<j;i++)
        for(k=i+1;k<j&&strip[k].y-strip[i].y<=o;k++)
        d=min(d,dist(strip[i],strip[k]));
    return d;
}
int main()
{
    int q,i,n,r,d;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d %d",&n,&r,&d);
        for(i=0;i<n;i++)
            scanf("%d %d",&a[i].x,&a[i].y);
        sort(a,a+n,cmpbyx);
        double dist=closest(a,n);
        printf((dist>=d+2*r)?"Y\n":"N\n");
    }
    return 0;
}
/*
5
2 1 1 0 0 4 0
2 1 1 0 0 2 0
3 1 2 0 0 -2 2 2 1
3 1 2 0 0 4 1 -4 0
3 1 2 0 0 3 1 -4 0
*/
