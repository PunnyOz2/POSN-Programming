/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long a[1000100];
int main()
{
	long long n,m,Max=0,ans,i,l,r,mid,ans1,cou,idx,num;
	scanf("%lld %lld",&n,&m);
	for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        Max=max(Max,a[i]);
	}
	l=Max,r=1000000000001;
	while(l<r){
        mid=(l+r)/2;
        cou=1;
        num=mid;
        for(i=1;i<=n;i++){
            if(num-a[i]<0){
                cou++;
                num=mid;
            }
            num-=a[i];
        }
        if(cou>=m)l=mid+1;
        else r=mid;
	}
	ans1=l;
	l=Max,r=1000000000001;
	while(l<r){
        mid=(l+r)/2;
        cou=1;
        num=mid;
        for(i=1;i<=n;i++){
            if(num-a[i]<0){
                cou++;
                num=mid;
            }
            num-=a[i];
        }
        if(cou>m)l=mid+1;
        else r=mid;
	}
	if(ans1==1000000000001)printf("-1\n");
	else printf("%lld\n",ans1-l);
    return 0;
}
/*
4 3
2 5 9 12
*/
