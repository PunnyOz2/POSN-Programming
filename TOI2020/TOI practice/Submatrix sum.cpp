#include<bits/stdc++.h>
using namespace std;
long long a[100010],b[100010],qs[100010];
int main(){
    long long n,h,k,Max,i,ans=0;
    scanf("%lld %lld %lld",&n,&h,&k);
    for(i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(i=1;i<=n;i++)scanf("%lld",&b[i]);
    Max=-1<<30;
    for(i=1;i<=n;i++)qs[i]=qs[i-1]+a[i];
    for(i=h;i<=n;i++)Max=max(Max,qs[i]-qs[i-h]);
    //printf("%lld\n",Max);
    ans+=Max*k;
    Max=-1<<30;
    for(i=1;i<=n;i++)qs[i]=qs[i-1]+b[i];
    for(i=k;i<=n;i++)Max=max(Max,qs[i]-qs[i-k]);
    ans+=Max*h;
    //printf("%lld\n",Max);
    printf("%lld\n",ans);
    return 0;
}
/*
8 6 3
1 9 8 3 4 5 6 4
9 5 2 5 1 8 8 2
*/
