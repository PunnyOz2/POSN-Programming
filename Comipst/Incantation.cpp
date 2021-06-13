/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long num[150];
long long dp[150][150][35],j,tmp[150][150],DP[150][150],Max;
int main()
{
    long long n,k,i,ii,l;
    scanf("%lld %lld",&n,&k);
    n=n-k+1;
    for(i=0;i<(1<<k);i++){
        scanf("%lld",&num[i]);
        dp[i][i][0]=num[i];
    }
    for(ii=1;ii<=27;ii++){
        for(i=0;i<(1<<k);i++){
            for(j=0;j<(1<<k);j++){
                for(l=0;l<(1<<k);l++){
                    dp[i][j][ii]=max(dp[i][j][ii],dp[i][l][ii-1]+dp[(l&((1<<(k-1))-1))*2][j][ii-1]);
                    dp[i][j][ii]=max(dp[i][j][ii],dp[i][l][ii-1]+dp[(l&((1<<(k-1))-1))*2+1][j][ii-1]);
                }
            }
        }
    }
    for(ii=0;ii<=27;ii++){
        if(!(n&(1<<ii)))continue;
        for(i=0;i<(1<<k);i++){
            for(j=0;j<(1<<k);j++){
                for(l=0;l<(1<<k);l++){
                    tmp[i][j]=max(tmp[i][j],DP[i][l]+dp[(l&((1<<(k-1))-1))*2][j][ii]);
                    tmp[i][j]=max(tmp[i][j],DP[i][l]+dp[(l&((1<<(k-1))-1))*2+1][j][ii]);
                }
            }
        }
        for(i=0;i<(1<<k);i++){
            for(j=0;j<(1<<k);j++){
                DP[i][j]=tmp[i][j];
                tmp[i][j]=0;
            }
        }
    }
    for(i=0;i<(1<<k);i++){
        for(j=0;j<(1<<k);j++){
            Max=max(DP[i][j],Max);
        }
    }
    printf("%lld\n",Max);
    return 0;
}
/*
5 2
1
5
4
1
*/
