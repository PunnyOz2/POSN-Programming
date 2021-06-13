/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long n;
struct A{
    long long x,y,num;
};
A a[100100],b[100100],c[100100];
void mergesort(long long l,long long r){
    if(l==r) return;
    long long i,j,mid=(l+r)/2,k;
    mergesort(l,mid);
    mergesort(mid+1,r);
    i=l,k=l,j=mid+1;
    while(i<=mid&&j<=r){
        if(a[i].num<=a[j].num)
            b[k++]=a[i++];
        else if(a[i].num>a[j].num)
            b[k++]=a[j++],b[k-1].x+=mid-i+1;
    }
    while(i<=mid)       b[k++]=a[i++];
    while(j<=r)         b[k++]=a[j++];
    for(i=l;i<=r;i++)   a[i]=b[i];
}
void mergesort2(long long l,long long r){
    if(l==r) return;
    long long i,j,mid=(l+r)/2,k;
    mergesort2(l,mid);
    mergesort2(mid+1,r);
    i=l,k=l,j=mid+1;
    while(i<=mid&&j<=r){
        if(c[i].num<=c[j].num)
            b[k++]=c[i++];
        else if(c[i].num>c[j].num)
            b[k++]=c[j++],b[k-1].y+=mid-i+1;
    }
    while(i<=mid)       b[k++]=c[i++];
    while(j<=r)         b[k++]=c[j++];
    for(i=l;i<=r;i++)   c[i]=b[i];
}
int main()
{
    int q;
    long long i,sum=0;
    scanf("%d",&q);
    while(q--){
        sum=0;
        scanf("%lld",&n);
        for(i=0;i<n;i++){
            scanf("%lld",&a[i].num);
            c[n-i-1].num=a[i].num*-1;
        }
        sum=0;
        mergesort(0,n-1);
        //for(i=0;i<n;i++)printf("%lld %lld %lld\n",a[i].num,a[i].x,a[i].y);
        mergesort2(0,n-1);
        //for(i=n-1;i>=0;i--)printf("%lld %lld %lld\n",c[i].num,c[i].x,c[i].y);
        for(i=0;i<n;i++)
            sum+=a[i].x*c[n-i-1].y;
        printf("%lld\n",sum);
        for(i=0;i<n;i++)a[i].x=c[i].y=0;
    }
    return 0;
}
/*
6
2 1 7 6 9 3 18 4 3 2 5 5
*/
