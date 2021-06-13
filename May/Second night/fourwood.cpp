/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dp[500100];
int main()
{
    int q,i,n;
    dp[0]=dp[1]=dp[2]=dp[3]=1;
    dp[4]=2;
    for(i=5;i<=100000;i++){
        dp[i]=(dp[i-1]+dp[i-4]);
        dp[i]%=100003;
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        printf("%d\n",dp[n]);
    }
    return 0;
}
