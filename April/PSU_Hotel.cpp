/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[103][100003];
long long qs[100003];
int main()
{
	long long i,j,k,n,p;
	scanf("%lld %lld %lld",&n,&k,&p);
	for(i=1;i<=n;i++)scanf("%lld",&qs[i]),qs[i]+=qs[i-1];
	if(k*p>n){printf("%lld\n",qs[n]);return 0;}
	for(i=1;i<=k;i++){
        for(j=i*p;j<=n;j++){
            dp[i][j]=max(dp[i][j-1],dp[i-1][j-p]+qs[j]-qs[j-p]);
        }
	}
	printf("%lld\n",dp[k][n]);
    return 0;
}
/*
9 3 2
2 5 1 9 1 7 3 4 5
*/
