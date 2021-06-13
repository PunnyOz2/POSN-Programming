/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[300100];
int main()
{
	int n,k,i,l,r,mid,ch,cou;
	scanf("%d %d",&n,&k);
	for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
	}
	l=1,r=1000000;
	while(l<r){
        mid=(l+r+1)/2;
        ch=1;
        cou=0;
        for(i=2;i<n;i++){
            if(a[i]<mid)cou++;
            else cou=0;
            if(cou>=k){ch=0;break;}
        }
        if(ch==0)r=mid-1;
        else l=mid;
	}
	printf("%d\n",l);
    return 0;
}
/*
10 2
51 16 52 36 21 81 42 52 73 1
*/
