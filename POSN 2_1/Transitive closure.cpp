/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dp[550][550];
int main()
{
	int n,i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&dp[i][j]);
        }
	}
	for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                dp[i][j]|=dp[i][k]&&dp[k][j];
            }
        }
	}
	for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%d ",dp[i][j]);
        }
        printf("\n");
	}
    return 0;
}
