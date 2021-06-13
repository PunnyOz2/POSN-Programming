/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long a[400100];
int main()
{
	long long n,i,Max=0,now;
	scanf("%lld",&n);
	for(i=0;i<n;i++){
        scanf("%lld",&a[i]);
	}
    sort(a,a+n);
    for(i=0;i<n-1;i++){
        now=(upper_bound(a,a+n,a[i]+a[i+1])-a);
        Max=max(Max,now-i);
    }
    printf("%lld\n",Max);
    return 0;
}
