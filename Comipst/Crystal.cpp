/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1200];
int main()
{
    int n,m,i,j;
    dp[0]=1;
    dp[1]=1;
    scanf("%d",&n);
    for(i=2;i<=n;i++){
        for(j=0;j<i;j++){
            dp[i]+=dp[j]*dp[i-j-1];
            dp[i]%=10001;
        }
    }
    printf("%d\n",dp[n]);
    return 0;
}
