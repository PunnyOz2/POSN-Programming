/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
#define INF 2e9
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
double dis(A a,A b){
    return sqrt((double)(a.x-b.x) * (a.x-b.x) +1.0*(a.y-b.y)*(a.y-b.y));
}
double closest(A b[],int n){
    double dl,dr,d,old;
    int mid,i,j,k;
    if(n<=3){
        for(i=0,d=INF;i<n;i++)
            for(j=i+1;j<n;j++)
            d=min(d,dis(b[i],b[j]));
        return d;
    }
    mid=n/2;
    dl=closest(b,mid);
    dr=closest(b+mid,n-mid);
    d=min(dl,dr);
    A strip[n+3],mp=b[mid];
    for(i=0,j=0;i<n;i++)
        if(abs(b[i].x-mp.x)<d)
            strip[j++]=b[i];
    sort(strip,strip+j,cmpbyy);
    old=d;
    for(i=0;i<j;i++)
        for(k=i+1;k<j&&strip[k].y-strip[i].y<=old;k++)
            d=min(d,dis(strip[i],strip[k]));
    return d;
}
int main()
{
	int q,n,i;
	double dist,r,d;
	scanf("%d ",&q);
	while(q--){
        scanf("%d %lf %lf",&n,&r,&d);
        for(i=0;i<n;i++)
            scanf("%d %d",&a[i].x,&a[i].y);
        sort(a,a+n,cmpbyx);
        dist=closest(a,n);
        printf((dist>=2*r+d)?"Y\n":"N\n");
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
