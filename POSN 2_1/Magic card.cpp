/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long a[5151],b[5151],dp[5151][5151];
int main()
{
	long long n,m,i,j;
	scanf("%lld %lld",&n,&m);
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(i=1;i<=m;i++)scanf("%lld",&b[i]);
	for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            dp[i][j]=max(dp[i-1][j-1]+abs(a[i]-b[j]),max(dp[i-1][j],dp[i][j-1]));
        }
	}
	printf("%lld",dp[n][m]);
    return 0;
}
