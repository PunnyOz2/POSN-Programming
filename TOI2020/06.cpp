/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000100],n,dp[3][1000100];
int main()
{
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    dp[1][0]=1<<30;
    for(i=1;i<=n;i++){
        if(i%2==1){
            dp[0][i]=dp[0][i-1]-a[i];
            dp[1][i]=min(dp[0][i-1]+a[i],dp[1][i-1]+a[i]);
            dp[2][i]=min(dp[1][i-1]-a[i],dp[2][i-1]-a[i]);
        }
        else{
            dp[0][i]=dp[0][i-1]+a[i];
            dp[1][i]=min(dp[0][i-1]-a[i],dp[1][i-1]-a[i]);
            dp[2][i]=min(dp[1][i-1]+a[i],dp[2][i-1]+a[i]);
        }
    }
    int Min=1<<30;
    for(i=0;i<=2;i++){
        Min=min(Min,dp[i][n]);
    }
    printf("%d\n",Min);
    return 0;
}
/*

*/
