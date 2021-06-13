/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[140][140];
long long play(int i,int j){
    int ii,jj;
    if(i==0 && j==0) return dp[i][j]=1;
    if(dp[i][j]!=0)return dp[i][j];
    if(i>0){
        dp[i][j]+=play(i-1,j);
        dp[i][j]%=9999991;
    }
    if(j>0){
        dp[i][j]+=play(i,j-1);
        dp[i][j]%=9999991;
    }
    for(ii=0;ii<=i-1;ii++){
        for(jj=0;jj<=j-1;jj++){
            dp[i][j]+=dp[ii][jj]*dp[i-1-ii][j-1-jj];
            dp[i][j]%=9999991;
        }
    }
    return dp[i][j];
}
int main()
{
	int q,i,j;
	scanf("%d",&q);
	play(125,125);
	while(q--){
        scanf("%d %d",&i,&j);
        printf("%lld\n",dp[i][j]);
	}
    return 0;
}
/*
2
1 1
2 1
*/
