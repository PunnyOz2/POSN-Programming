/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int dp[2000100],dp2[2000100];
int main()
{
    int q,i,n;
    dp[1]=1;
    dp[0]=1;
    for(i=2;i<=2000000;i++){
        dp[i]=(dp[i-1]%mod+dp[i-2]%mod)%mod;
    }
    for(i=1;i<=1000000;i++){
        dp2[i]=(((dp[i*2]%mod+dp2[i-2]%mod)%mod)+dp2[i-1]%mod)%mod;
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        printf("%d\n",(dp2[n]%mod+dp[n]%mod)%mod);
    }
    return 0;
}
