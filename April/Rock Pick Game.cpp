/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[120];
int dp[120][120];
int play(int l,int r){
    if(l>=r) return 0;
    if(dp[l][r])return dp[l][r];
    int Max=0;
    Max=max(Max,play(l+2,r)+a[l]);
    Max=max(Max,play(l+1,r-1)+a[l]);
    Max=max(Max,play(l+1,r-1)+a[r]);
    Max=max(Max,play(l,r-2)+a[r]);
    return dp[l][r]=Max;
}
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n*2;i++){
        scanf("%d",&a[i]);
	}
	printf("%d",play(1,2*n));
    return 0;
}
/*
2
1 20 19 2
*/
