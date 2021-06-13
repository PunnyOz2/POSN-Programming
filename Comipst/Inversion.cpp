/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100100],cou,b[100100];
void mergesort(long long l,long long r){
    if(l==r)return;
    long long mid=(l+r)/2,i;
    long long ll=l,rr=mid+1,idx=l;
    mergesort(l,mid);
    mergesort(mid+1,r);
    while(ll<=mid && rr<=r){
        if(a[ll]>a[rr])b[idx++]=a[rr++],cou+=mid-ll+1;
        else b[idx++]=a[ll++];
    }
    while(ll<=mid){
        b[idx++]=a[ll++];
    }
    while(rr<=r){
        b[idx++]=a[rr++];
    }
    for(i=l;i<=r;i++){
        a[i]=b[i];
    }
}
int main()
{
    long long n,i;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    mergesort(1,n);
    printf("%lld\n",cou);
    return 0;
}
/*
5
10
40
30
50
20
*/
