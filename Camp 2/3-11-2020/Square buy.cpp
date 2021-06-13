/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dp[100100];
int main()
{
    int q,n,m,i,j;
    for(i=1;i<=100000;i++)dp[i]=1<<30;
    for(i=1;i<=317;i++){
        for(j=i*i;j<=100000;j++){
            dp[j]=min(dp[j],dp[j-i*i]+1);
        }
    }
    //for(i=1;i<=100;i++)printf("%d %d\n ",i,dp[i]);
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&m);
        printf("%d\n",dp[n]%m);
    }
    return 0;
}
/*

*/
