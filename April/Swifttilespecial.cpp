/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dp[120][120];
int main()
{
	int q,i,j,ii,n,k;
	scanf("%d",&q);
	for(j=0;j<=100;j++){
        dp[0][j]=1;
        for(i=1;i<=100;i++){
            dp[i][j]+=dp[i-1][j]%9241;
            if(i>=2)dp[i][j]+=dp[i-2][j]%9241;
            if(i>=2 && j>=1)dp[i][j]+=dp[i-2][j-1]%9241;
            if(i>=3 && j>=2){
                for(ii=3;ii<=i;ii++){
                    dp[i][j]+=(dp[i-ii][j-2]*2)%9241;
                }
            }
            dp[i][j]%=9241;
        }
	}
	while(q--){
        scanf("%d %d",&n,&k);
        printf("%d\n",dp[n][k]);
	}
    return 0;
}
