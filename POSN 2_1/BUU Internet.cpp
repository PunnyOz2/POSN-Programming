/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long a[25];
int main()
{
    long long l,r,m,n,i,mid,mid2,cou,last,ma=-10000000;
    scanf("%lld %lld",&m,&n);
    for(i=0;i<n;i++){
        scanf("%lld",&a[i]);
        ma=max(a[i],ma);
    }
	l=ma;r=1000000000;
	while(l<r){
        mid=(l+r)/2;
        last=0;
        for(i=0,cou=1;i<n;i++){
            if(a[i]+last>mid)cou++,last=a[i];
            else last+=a[i];
        }
        if(cou<=m)r=mid;
        else l=mid+1;
	}
	printf("%lld",l);
    return 0;
}
