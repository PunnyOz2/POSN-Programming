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
	long long n,m,i,l,r,sum,mid;
	scanf("%lld %lld",&n,&m);
	for(i=0;i<n;i++){
        scanf("%lld",&a[i]);
	}
    l=0;r=1000000000000000000;
	while(l<r){
        sum=0;
        mid=(l+r+1)/2;
        for(i=0;i<n;i++){
            if(a[i]-mid>0) sum+=a[i]-mid;
        }
        if(sum>=m)l=mid;
        else r=mid-1;
	}
	printf("%lld",l);
    return 0;
}
