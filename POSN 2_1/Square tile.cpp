/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dp[400][400],i,Min,r,c,j;
int main()
{
	int n,m,q,k;
	scanf("%d",&q);
	for(i=1;i<=350;i++){
        for(j=1;j<=350;j++){
            dp[i][j]=1<<30;
        }
	}
	for(k=1;k<=350;k++){
        dp[k][k]=1;
	}
	for(i=1;i<=350;i++){
        for(j=1;j<=350;j++){
            Min=i*j;
            for(r=1;r<i;r++){
                Min=min(dp[r][j]+dp[i-r][j],Min);
            }
            for(c=1;c<j;c++){
                Min=min(dp[i][c]+dp[i][j-c],Min);
            }
            dp[i][j]=min(Min,dp[i][j]);
        }
	}
	while(q--){
        scanf("%d %d",&n,&m);
        printf("%d\n",dp[n][m]);
	}
    return 0;
}
/*
3
4 4
1 5
2 3
*/
