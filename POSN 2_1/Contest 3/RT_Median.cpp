/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
float a[100100];
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
        scanf("%f",&a[i]);
	}
	sort(a+1,a+n+1);
	if(n%2==1){
        printf("%.1f",a[(n+1)/2]);
	}
	else {
        printf("%.1f",(a[n/2]+a[(n/2)+1])/2);
	}
    return 0;
}
