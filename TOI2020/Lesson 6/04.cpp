#include<bits/stdc++.h>
using namespace std;
long long a[500100],b[500100];
int main(){
    long long n,i,Max=0,Min=1e18;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++){
        scanf("%lld",&b[i]);
        b[i]*=-1;
    }
    sort(b+1,b+n+1);
    for(i=1;i<=n;i++)b[i]*=-1;
    for(i=1;i<=n;i++){
        Max=max(Max,a[i]+b[i]);
        Min=min(Min,a[i]+b[i]);
    }
    printf("%lld\n",Max-Min);
    return 0;
}
/*
3
158 168 139
132 104 140
*/
