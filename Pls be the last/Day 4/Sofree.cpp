/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long temp[5000],dp[5000],a[5000];
int main()
{
    long long n,i,now,j;
    dp[0]=1;
    scanf("%lld",&n);
    for(i=0;i<n;i++)scanf("%lld",&now),a[now]++;
    for(i=0;i<2048;i++){
        for(j=0;j<2048;j++)
            temp[j^i]+=dp[j]*a[i];
        for(j=0;j<2048;j++){
            dp[j]+=temp[j];
            dp[j]%=1000000007;
        }
        memset(temp,0,sizeof temp);
    }
    scanf("%lld",&now);
    printf("%lld\n",dp[now]);
    return 0;
}
