/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000100];
int l[1000100];
int r[1000100];
int main()
{
	int n,i,Min,Max,val,now,anss=0,first,Maxn;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
	}
	Maxn=1<<30;
	for(i=1;i<=n;i++){
	    l[i]=max(l[i-1],a[i]-Maxn);
	    Maxn=min(Maxn,a[i]);
	    //printf("%d ",l[i]);
	}
	Maxn=a[n];
	for(i=n-1;i>=1;i--){
	    r[i]=max(r[i+1],Maxn-a[i]);
	    Maxn=max(Maxn,a[i]);
	    //printf("%d ",r[i]);
	}
	Max=0;
	for(i=1;i<=n;i++){
	    Max=max(Max,l[i]+r[i+1]);
	}
	printf("%d\n",Max);
    return 0;
}
/*
10
2 5 2 5 7 7 34 12 5 21
*/
