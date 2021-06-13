/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long a[500100],b[500100];
int main()
{
    long long n,i;
    long long suma=0,sumb=0,ans=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%lld %lld",&a[i],&b[i]);
        suma+=a[i];
        sumb+=b[i];
    }
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    for(i=1;i<=n;i++){
        suma-=a[i];
        sumb-=b[i];
        ans+=suma-a[i]*(n-i);
        ans+=sumb-b[i]*(n-i);
    }
    printf("%lld\n",ans);
    return 0;
}
