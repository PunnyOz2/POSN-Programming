/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[50000];
int main()
{
	int n,k,Max=0,i,ans;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++){
        scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
        ans=(upper_bound(a,a+n,a[i]+k)-a)-(upper_bound(a,a+n,a[i])-a);
        Max=max(Max,ans);
	}
	printf("%d",Max);
    return 0;
}
