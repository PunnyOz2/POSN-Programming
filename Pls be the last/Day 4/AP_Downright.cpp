/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1010][1010][3],a[1010][1010];
int main()
{
    int q,n,m,i,j,Max;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                scanf("%d",&a[i][j]);
            }
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                dp[i][j][0]=max(dp[i][j][0],dp[i-1][j][0]);
                dp[i][j][0]=max(dp[i][j][0],dp[i-1][j][1]);
                dp[i][j][0]=max(dp[i][j][0],dp[i-1][j][2]);
                dp[i][j][0]=max(dp[i][j][0],dp[i][j-1][0]);
                dp[i][j][0]=max(dp[i][j][0],dp[i][j-1][1]);
                dp[i][j][0]=max(dp[i][j][0],dp[i][j-1][2]);
                dp[i][j][1]=max(dp[i][j][1],dp[i][j-1][0]+a[i][j]);
                dp[i][j][1]=max(dp[i][j][1],dp[i-1][j][0]+a[i][j]);
                dp[i][j][2]=max(dp[i][j][2],dp[i][j-1][1]+a[i][j]);
                dp[i][j][2]=max(dp[i][j][2],dp[i-1][j][1]+a[i][j]);
//                Max=max(dp[i][i][0],max(dp[i][j][1],dp[i][j][2]));
//                printf("%d ",Max);
            }
//            printf("\n");
        }
        Max=max(dp[n][m][0],max(dp[n][m][1],dp[n][m][2]));
        printf("%d\n",Max);
        memset(dp,0,sizeof dp);
    }
    return 0;
}
/*
1
5 5
1 1 3 2 1
1 1 2 9 1
1 1 1 9 1
1 1 1 1 9
1 1 1 1 1
*/
