/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long h,w;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
A a[1000100],b[1000100];
int main()
{
    long long n,Max=0,j=0,i;
    scanf("%lld",&n);
    for(i=0;i<n;i++){
        scanf("%lld %lld",&a[i].h,&a[i].w);
    }
    sort(a,a+n);
    for(i=0;i<n;i++){
        if(Max>=a[i].h)continue;
        Max=max(Max,a[i].h);
        b[j++]=a[i];
    }
    long long ans=0;
    ans+=b[0].h*b[0].w;
    for(i=1;i<j;i++){
        ans+=(b[i].h-b[i-1].h)*b[i].w;
    }
    printf("%lld\n",ans);
    return 0;
}
/*
10
a 0
a 1
a 2
a 3
a 2
c 4 5
a 5
b 7
b 7
c 9 7
*/
