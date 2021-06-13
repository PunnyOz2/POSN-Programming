/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[2][50003];
long long qs[50003];
int main()
{
    int n,k,m;
    scanf("%d %d %d",&n,&k,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&qs[i]),qs[i]+=qs[i-1];
    for(int i=1;i<=k;i++){
        long long mi=1e18;
        for(int j=i*m+i-1;j<=n;j++){
            mi=min( mi,-qs[j-m]+( dp[ ( i-1 )%2 ][ max(0,j-m-1) ] ) );
            dp[i%2][j]=qs[j]+mi;
            if(j!=i*m+i-1) dp[i%2][j]=min(dp[i%2][j],dp[i%2][j-1]);
        }
    }
    printf("%lld\n",qs[n]-dp[k%2][n]);
    return 0;
}
/*
7 1 3
1 0 4 8 5 7 6

12 3 2
2 -8 3 -4 5 -7 3 5 -2 2 4 1

*/
