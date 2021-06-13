/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[505],dp[505][25][25];
int main()
{
	int q,n,i,k,j;
	scanf("%d",&q);
	while(q--){
        scanf("%d",&n);
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        for(i=0;i<=n;i++)
            for(j=0;j<=20;j++)
                for(k=0;k<=20;k++)dp[i][j][k]=1<<30;
        dp[0][0][0]=0;
        for(i=1;i<=n;i++){
            for(j=0;j<=20;j++){
                for(k=0;k<=20;k++){
                    if(a[i]!=j && a[i]!=k)continue;
                    if(a[i]==j){
                        for(int l=0;l<=20;l++){
                            dp[i][j][k]=min(dp[i][j][k],dp[i-1][l][k]+(l!=j));
                        }
                    }
                    if(a[i]==k){
                        for(int l=0;l<=20;l++){
                            dp[i][j][k]=min(dp[i][j][k],dp[i-1][j][l]+(l!=k));
                        }
                    }
                }
            }
        }
        int Min=1<<30;
        for(i=0;i<=20;i++)
            for(j=0;j<=20;j++)Min=min(Min,dp[n][i][j]);
        printf("%d\n",Min);
	}
    return 0;
}
/*
2
5
7 7 2 11 7
10
9 1 7 6 9 9 8 7 6 7
*/
