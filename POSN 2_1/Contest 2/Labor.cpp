/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long a[1000010];
int main()
{
	long long n,m,i,ans=0,l,r,mid;
	scanf("%lld %lld",&n,&m);
	for(i=0;i<n;i++){
        scanf("%lld",&a[i]);
	}
	l=0,r=1e18;
	while(l<r){
        mid=(l+r)/2;
        ans=0;
        for(i=0;i<n;i++)
            ans+=(mid/a[i]);
        if(ans<m)   l=mid+1;
        else        r=mid;
	}
	printf("%lld\n",l);
    return 0;
}
