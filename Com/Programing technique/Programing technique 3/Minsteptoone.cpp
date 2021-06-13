/*
    TASK:
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1000100];
int main()
{
   int i,q;
   for(i=2;i<=1000000;i++){
        dp[i] = dp[i-1]+1; //P = P-1
        if(i%2==0 && dp[i/2]+1 < dp[i])
            dp[i] = dp[i/2]+1; //case2
        if(i%3==0 && dp[i/3]+1 < dp[i])
            dp[i] = dp[i/3]+1;
   }
   scanf("%d",&q);
   while(q--){
    scanf("%d",&i);
    printf("%d",dp[i]);
   }

    return 0;
}

