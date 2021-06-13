/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[100100][2];
long long a[100100];
int main()
{
    long long q,n,i;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld",&n);
        for(i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        for(i=2;i<=n;i++){
            dp[i][0]=max(dp[i-1][0]+abs(a[i]-a[i-1]),dp[i-1][1]+a[i]-1);
            dp[i][1]=max(dp[i-1][0]+a[i-1]-1,dp[i-1][1]);
        }
        printf("%lld\n",max(dp[n][0],dp[n][1]));
    }
    return 0;
}
/*
2
5
10 5 10 5 10
5
10 5 10 5 10
*/
