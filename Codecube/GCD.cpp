/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long Max=-(1e18),Min,a[1000100];
int main()
{
    long long n,m,i;
	scanf("%lld %lld",&n,&m);
	for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        a[i]+=a[i-1];
	}
	for(i=m;i<=n;i++){
        Min=min(Min,a[i-m]);
        Max=max(Max,a[i]-Min);
	}
	printf("%lld\n",Max);
    return 0;
}
/*
6 6
5
-6
3
-2
4
1
*/
