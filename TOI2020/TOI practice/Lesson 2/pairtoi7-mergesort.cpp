#include<bits/stdc++.h>
using namespace std;
struct A{
    long long x,y;
    bool operator<(const A&o)const{
        return y<o.y;
    }
};
A a[100100];
long long b[100100],temp[100100];
long long ans;
long long qs[100100];
void mergesort(long long l,long long r){
    long long mid,i,j,cou;
    if(l==r)return;
    mid=(l+r)/2;
    mergesort(l,mid);
    mergesort(mid+1,r);
    i=l;
    qs[l-1]=0;
    for(i=l;i<=mid;i++){
        qs[i]=qs[i-1]+b[i];
        if(b[i]<0)qs[i]-=b[i]*2;
        //printf("%lld ",qs[i]);
    }
    //printf("\n");
    i=l;
    j=mid+1;
    cou=l;
    while(i<=mid && j<=r){
        if(b[i]>b[j]){
            temp[cou++]=b[j++];
            ans+=qs[mid]-qs[i-1];
        }
        else{
            temp[cou++]=b[i++];
        }
    }
    while(i<=mid){
        temp[cou++]=b[i++];
    }
    while(j<=r){
        temp[cou++]=b[j++];
    }
    for(i=l;i<=r;i++){
        b[i]=temp[i];
    }
    return;
}
int main(){
    long long n,i,sum=0;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld %lld",&a[i].x,&a[i].y);
    }
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++)b[i]=a[i].x;
//    for(i=1;i<=n;i++)printf("%d ",b[i]);
//    printf("\n");
    mergesort(1,n);
    for(i=1;i<=n;i++)b[i]=-a[n-i+1].x;
    mergesort(1,n);
    printf("%lld\n",ans);
    return 0;
}
/*
6
2 1
7 6
9 3
18 4
3 2
5 5

4
5 1
4 2
3 3
2 4

6
2 1
3 2
9 3
18 4
5 5
7 6
*/
