/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[15100][2];
int ans[15100];
int b[15100];
int main()
{
	int i,j,n,k,Min,idx;
	scanf("%d %d",&n,&k);
	for(i=1;i<=n;i++)scanf("%d %d",&a[i][0],&a[i][1]),b[i]=1<<30;
	for(i=1;i<n;i++){
        Min=1000100;
        for(j=i+1;j<=n;j++){
            if(b[j]>abs(a[i][0]-a[j][0])+abs(a[i][1]-a[j][1]))b[j]=abs(a[i][0]-a[j][0])+abs(a[i][1]-a[j][1]);
            if(Min>b[j])Min=b[j],idx=j;
        }
    swap(a[i+1][0],a[idx][0]);
    swap(a[i+1][1],a[idx][1]);
    swap(b[i+1],b[idx]);
	}
	sort(b+2,b+n+1);
	long long cou=0;
	for(i=2;i<=n-k+1;i++)cou+=b[i];
	printf("%lld\n",cou);
    return 0;
}
/*
5 2
2 9
9 7
14 2
12 9
16 4
*/
