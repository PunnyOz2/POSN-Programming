#include <bits/stdc++.h>
using namespace std;
vector<int> a[500100];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf(" %s",b+1);
        a[i].push_back(0);
        for(j=1;j<=m;j++){
            if(b[j]=='R')a[i].push_back(1);
            else a[i].push_back(2);
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            temp1=temp2=0;
            if(a[i][j]==1)temp1=1;
            else temp2=1;
            if(Max<max(dp[i][j-1][1]+temp1,dp[i][j-1][2]+temp2)){
                dp[i][j][1]=dp[i][j-1][1]+temp1;
                dp[i][j][2]=dp[i][j-1][2]+temp2;
            }
            if(Max<max(dp[i-1][j][1]+temp1,dp[i-1][j][2]+temp2))
        }
    }
}
/*
5 5
RRGRG
RGRGR
GRRRR
RRGRG
GRGRR
*/
