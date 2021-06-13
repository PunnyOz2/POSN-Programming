/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[1001000],qs[1000100];
int main()
{
    long long q,n,m,i;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld",&n,&m);
        dp[0]=1;
        qs[0]=1;
        for(i=1;i<=min(n,m-1);i++){
            dp[i]=dp[i-1]*i;
            qs[i]=qs[i-1]+dp[i];
            dp[i]%=m;
            qs[i]%=m;
        }
        printf("%lld\n",qs[min(n,m-1)]);
    }
    return 0;
}
/*
1
10 861017
*/
