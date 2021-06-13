#include<bits/stdc++.h>
using namespace std;
int dp[510][510];
int main(){
    int q,i,k,j,l,n,m;
    scanf("%d",&q);
    for(i=0;i<=33;i++){
        for(j=0;j<=33;j++){
            for(k=500;k>=i;k--){
                for(l=500;l>=j;l--){
                    dp[k][l]=max(dp[k][l],dp[k-i][l-j]+1);
                }
            }
        }
    }
    while(q--){
        scanf("%d %d",&n,&m);
        printf("%d\n",dp[n][m]-1);
    }
    return 0;
}
/*
4
2 0
3 0
3 1
4 5
*/
