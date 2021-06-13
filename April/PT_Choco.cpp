/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dp[600][600];
int main()
{
	int q,i,j,k,l;
	scanf("%d",&q);
	memset(dp,-1,sizeof dp);
	dp[0][0]=0;
	for(i=0;i<=34;i++){
        for(j=0;j<=34;j++){
            if(i==0 && j==0)continue;
            for(k=500;k>=i;k--){
                for(l=500;l>=j;l--){
                    if(dp[k-i][l-j]>=0)dp[k][l]=max(dp[k][l],dp[k-i][l-j]+1);
                }
            }
        }
	}
	while(q--){
        scanf("%d %d",&i,&j);
        printf("%d\n",dp[i][j]);
	}
    return 0;
}
