#include<bits/stdc++.h>
using namespace std;
int dp[110][110],qs[110][110];
int main(){
    int q,n,k,i,j,sum,kk;
    scanf("%d",&q);
    while(q--){
        sum=0;
        scanf("%d %d",&n,&k);
        dp[0][0]=1;
        qs[0][0]=1;
        for(i=1;i<=n;i++){
            for(j=0;j<=k;j++){
                dp[i][j]+=dp[i-1][j];
                if(i>=2)dp[i][j]+=dp[i-2][j];
                if(i>=2 && j>=1)dp[i][j]+=dp[i-2][j-1];
                if(i>=3 && j>=2)dp[i][j]+=qs[i-3][j-2]*2;
                if(i>=4 && j>=2)dp[i][j]+=qs[i-4][j-2]*2;
                qs[i][j]=dp[i][j];
                if(i>=2)qs[i][j]+=qs[i-2][j];
                qs[i][j]%=9241;
                dp[i][j]%=9241;
            }
        }
        for(i=0;i<=k;i++)sum+=dp[n][i],sum%=9241;
        printf("%d\n",sum);
        memset(dp,0,sizeof dp);
    }
    return 0;
}
/*
3
3 0
3 1
3 2

3 5 7
*/
