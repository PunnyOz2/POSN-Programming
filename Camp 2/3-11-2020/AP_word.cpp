/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char a[5010],b[5010];
int dp[5010][5010];
int main()
{
    int q,n,m,i,j;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&m);
        scanf(" %s %s",a+1,b+1);
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                if(a[i]==b[j])dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
        printf("%d\n",n+m-dp[n][m]);
    }
    return 0;
}
/*

*/
