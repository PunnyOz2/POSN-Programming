#include <bits/stdc++.h>
using namespace std;
int dp[1000100];
pair<int,int> a[5];
int main(){
    int n,i,j,tempc,tempp;
    scanf("%d",&n);
    a[1]={1,500};
    a[2]={2,800};
    a[3]={5,1500};
    a[4]={15,3000};
    for(i=1;i<=1000015;i++){
        dp[i]=1<<30;
    }
    for(i=4;i>=1;i--){
        tempc=a[i].first;
        tempp=a[i].second;
        for(j=tempc;j<=1000015;j++){
            dp[j]=min(dp[j-tempc]+tempp,dp[j]);
        }
    }
    int Min=1<<30;
    for(i=1000015;i>=1;i--){
        Min=min(Min,dp[i]);
        dp[i]=Min;
    }
    printf("%d\n",dp[n]);
}
/*
24
6000
*/
