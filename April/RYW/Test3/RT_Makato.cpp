/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[100100],b[100100];
int main()
{
	int n,q,ans=0,i,j;
	scanf("%d %d",&n,&q);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	b[1]=a[1];
	for(i=2;i<=n;i++)b[i]=a[i]^b[i-1];
	while(q--){
        scanf("%d %d",&i,&j);
        printf("%d\n",b[j]^b[i-1]);
	}
    return 0;
}
