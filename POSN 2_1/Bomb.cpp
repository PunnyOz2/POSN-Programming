/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long Plus,Mul,l,r,mid;
	scanf("%lld %lld",&Plus,&Mul);
	l=0,r=Plus/2;
	while(l<r){
        mid=(l+r)/2;
        if( mid>=1e19/(Plus-mid)|| mid*(Plus-mid)>=Mul)r=mid;
        else l=mid+1;
	}
	if(l*(Plus-l)==Mul)
        printf("%lld %lld",l,Plus-l);
    else printf("Goodbye T-T");
    return 0;
}
