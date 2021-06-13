/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long dp[1100][5][5][1100];
int main()
{
    //dp[date][now][mark][how long]
    long long n,na,nb,nc,i,j;
    scanf("%lld %lld %lld %lld",&n,&na,&nb,&nc);
    dp[1][1][0][1]=1;
    for(i=2;i<=n;i++){
        for(j=1;j<=na+1;j++){
            //A to A
            dp[i][1][0][j]+=dp[i-1][1][0][j-1];
            dp[i][1][1][j]+=dp[i-1][1][1][j-1];
            dp[i][1][2][j]+=dp[i-1][1][2][j-1];
            dp[i][1][3][j]+=dp[i-1][1][3][j-1];
            dp[i][1][0][j]%=MOD;
            dp[i][1][1][j]%=MOD;
            dp[i][1][2][j]%=MOD;
            dp[i][1][3][j]%=MOD;
            //A to B
            dp[i][2][2][1]+=dp[i-1][1][0][j-1];
            dp[i][2][3][1]+=dp[i-1][1][3][j-1]+dp[i-1][1][1][j-1];
            dp[i][2][3][1]%=MOD;
            dp[i][2][2][1]%=MOD;
            //A to C
            dp[i][3][1][1]+=dp[i-1][1][1][j-1]+dp[i-1][1][0][j-1];
            dp[i][3][3][1]+=dp[i-1][1][2][j-1]+dp[i-1][1][3][j-1];
            dp[i][3][1][1]%=MOD;
            dp[i][3][3][1]%=MOD;
        }
        for(j=1;j<=nb+1;j++){
            //B to B
            dp[i][2][2][j]+=dp[i-1][2][2][j-1];
            dp[i][2][3][j]+=dp[i-1][2][3][j-1];
            dp[i][2][2][j]%=MOD;
            dp[i][2][3][j]%=MOD;
            //B to C
            dp[i][3][3][1]+=dp[i-1][2][2][j-1]+dp[i-1][2][3][j-1];
            dp[i][3][3][1]%=MOD;
        }
        for(j=1;j<=nc+1;j++){
            //C to C
            dp[i][3][1][j]+=dp[i-1][3][1][j-1];
            dp[i][3][3][j]+=dp[i-1][3][3][j-1];
            dp[i][3][1][j]%=MOD;
            dp[i][3][3][j]%=MOD;
            //C to A
            dp[i][1][1][1]+=dp[i-1][3][1][j-1];
            dp[i][1][3][1]+=dp[i-1][3][3][j-1];
            dp[i][1][1][1]%=MOD;
            dp[i][1][3][1]%=MOD;
            //printf("%d\n",dp[i][3][3][j]);
        }
    }
    long long ans=0;
    for(j=1;j<=na;j++){
        ans+=dp[n][1][3][j];
        ans%=MOD;
    }
    for(j=1;j<=nb;j++){
        ans+=dp[n][2][3][j];
        ans%=MOD;
    }
    for(j=1;j<=nc;j++){
        ans+=dp[n][3][3][j];
        ans%=MOD;
    }
    ans%=MOD;
    printf("%lld\n",ans);
    return 0;
}
/*
40 20 20 20
*/
