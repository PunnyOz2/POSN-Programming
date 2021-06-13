/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000100],b[1000100];
int dp[1000100];
int main()
{
	int n,i,j,Max=-1,idx;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&a[i]),b[i]=a[i];
	int cnt=0;
	for(i=0;i<n;i++){
        idx=upper_bound(dp,dp+cnt,a[i])-dp;
        if(cnt==idx)cnt++;
        dp[idx]=a[i];
	}
	//for(i=1;i<=n;i++)printf("%d ",dp[i]);
	printf("%d\n",n-cnt);
    return 0;
}
