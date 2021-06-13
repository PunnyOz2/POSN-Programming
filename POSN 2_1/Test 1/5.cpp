/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[200100];
int main()
{
	int n,i,j,cou=0,mid;
	scanf("%d",&n);
	//all is open
	mid=sqrt(n);
	for(i=2;i<=n;i++){
        for(j=i;j<=n;j+=i) a[j]++;
	}
	for(i=1;i<=n;i++){
        if(a[i]%2==0)cou++;
	}
	printf("%d",cou);
    return 0;
}
