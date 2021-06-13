/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long qs[100100];
long long a[100100];
int main()
{
    long long n,m,Max=-1,i,l,r,mid,idx,now;
    scanf("%lld %lld",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        Max=max(Max,a[i]);
    }
    sort(a+1,a+1+n);
    for(i=1;i<=n;i++){
        qs[i]=a[i]+qs[i-1];
    }
    l=qs[n]/n,r=1000000001;
    if(qs[n]%n!=0)l++;
    while(l<r){
        mid=(l+r)/2;
        idx=upper_bound(a+1,a+1+n,mid)-a;
        idx--;
        now=qs[n]-qs[idx];
        now-=(n-idx)*mid;
        if(now<=m)r=mid;
        else l=mid+1;
    }
    printf("%lld\n",l);
    return 0;
}
/*
5 7
11 3 8 3 4
*/
