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
	long long n,m,l,r,mid,sum,i;
	scanf("%lld %lld",&n,&m);
	for(i=0;i<n;i++){
        scanf("%lld",&a[i]);
	}
	l=0,r=20000000000000000;
    while(l<r){
        sum=0;
        mid=(l+r)/2;
        for(i=0;i<n;i++){
            sum+=(mid/a[i]);
        }
        if(sum>=m)r=mid;
        else l=mid+1;
    }
    printf("%lld",l);
    return 0;
}
