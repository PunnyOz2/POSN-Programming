/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[2010],b[2010];
int main()
{
	int n,sum=0,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	for(i=0;i<n;i++)scanf("%d",&b[i]);
	sort(a,a+n);
	sort(b,b+n);
	for(i=0;i<n;i++){
        sum+=abs(a[i]-b[i]);
	}
	printf("%d",sum);
    return 0;
}
