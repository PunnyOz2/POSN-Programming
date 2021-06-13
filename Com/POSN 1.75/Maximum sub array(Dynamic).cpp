/*
    TASK: Maximum sub array
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dp[510][510];
int main()
{
    int n,i,j,k,sum,ans=-2000000000;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&dp[i][j]);
            dp[i][j]+=dp[i-1][j];
        }
    }
    ans=dp[1][1];
    for(k=1;k<=n;k++){
        for(i=1;i<=n-k+1;i++){
            for(j=1,sum=0;j<=n;j++){
                sum+=dp[i+k-1][j]-dp[i-1][j];
                if(sum<0)
                    sum=dp[i+k-1][j]-dp[i-1][j];
                ans = max(ans,sum);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
4
0 -2 7 0
9 2 -6 2
-4 1 -4 1
-1 8 0 -2
*/
