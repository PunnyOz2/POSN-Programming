#include<bits/stdc++.h>
using namespace std;
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
    return sqrt((1.0)*(a.x-b.x)*(a.x-b.x)+(1.0)*(a.y-b.y)*(a.y-b.y));
}
double closest(A a[],int n){
    int i,j,k;
    double d,dl,dr,old;
    if(n<=3){
        d=1<<30;
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++)d=min(d,dis(a[i],a[j]));
        }
        return d;
    }
    int mid=n/2;
    dl=closest(a,mid);
    dr=closest(a+mid,n-mid);
    old=d=min(dl,dr);
    A temp[n+5];
    j=0;
    for(i=0;i<n;i++){
        if(abs(a[i].x-a[mid].x)<d){
            temp[j++]=a[i];
        }
    }
    sort(temp,temp+j,cmpbyy);
    for(i=0;i<j;i++){
        for(k=i+1;k<j && abs(temp[i].y-temp[k].y)<=old;k++){
            d=min(d,dis(temp[i],temp[k]));
        }
    }
    return d;
}
int main(){
    int n,q,i;
    double dis,r,d;
    scanf("%d",&q);
    while(q--){
        scanf("%d %lf %lf",&n,&r,&d);
        for(i=0;i<n;i++){
            scanf("%d %d",&a[i].x,&a[i].y);
        }
        sort(a,a+n,cmpbyx);
        dis=closest(a,n);
        if(dis>=d+r*2)printf("Y\n");
        else printf("N\n");
    }
    return 0;
}
/*
5
2 1 1 0 0 4 0
2 1 1 0 0 2 0
*/
