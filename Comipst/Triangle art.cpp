/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
#define MOD (int )(1e9+7)
using namespace std;
int dp[120][120];
int main()
{
    int n,k,i,j,l;
    scanf("%d %d",&n,&k);
    dp[2][1] = dp[1][2] = 1;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if((i == 1 && j == 2) || (i == 2 && j == 1))    continue;
            dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
            dp[i][j]%=MOD;
            for(l=i-1;l>=i-k &&  l>=1;l--){
                dp[i][j]+=dp[l-1][j-1]+1;
                dp[i][j]%=MOD;
            }
            for(l=j-1;l>=j-k &&  l>=1;l--){
                dp[i][j]+=dp[i-1][l-1]+1;
                dp[i][j]%=MOD;
            }
        }
    }
    printf("%d\n",dp[n][n]);
    return 0;
}
