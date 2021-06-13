/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
double b[300100],l,r,mid,now,Max2=0,Min;
int a[300100];
int main()
{
	int n,k,ch,i,Max=0;
	double mi;
	scanf("%d %d",&n,&k);
	for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]+=a[i-1];
        Max=max(a[i],Max);
	}
	l=0,r=Max;
    while(l<r){
        ch=1;
        printf("%f %f\n",l,r);
        mid=(l+r)/2;
        mi=1<<30;
        for(i=k;i<=n;i++){
            if(a[i]-i*mid>=mi)ch=0;
            mi=min(mi,a[i-k+1]-(i-k+1)*mid);
        }
        if(ch==0)l=mid;
        else r=mid-1/10;
    }
    printf("%.1f\n",l);
    return 0;
}
