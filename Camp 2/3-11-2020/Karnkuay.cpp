/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[100100];
long long a[100100];
int main()
{
    long long n,i;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(i=3;i<=n;i++){
        dp[i]=max(dp[i-3]+a[i],max(dp[i-2],dp[i-1]));
    }
    printf("%lld\n",dp[n]);
    return 0;
}
/*
12
1
2
5
4
3
0
6
1
2
7
2
1
*/
