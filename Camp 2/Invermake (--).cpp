/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[1110][10110],qs[1110][10110];
int main()
{
    long long n,k,i,j,kk;
    scanf("%lld %lld",&n,&k);
    dp[0][0]=1;
    for(i=1;i<=n;i++){
        for(j=0;j<=k;j++){
            if(j==0)dp[i][j]=1;
            else{
                dp[i][j]=qs[i-1][j];
                if(j>=i){
                    dp[i][j]-=qs[i-1][j-i];
                }
                dp[i][j]%=1000000007;
            }
            if(j==0)qs[i][j]=dp[i][j];
            else qs[i][j]=dp[i][j]+qs[i][j-1];
            qs[i][j]%=1000000007;
        }
    }
    printf("%lld\n",dp[n][k]);
    return 0;
}
/*

*/
