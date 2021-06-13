/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int cost[5];
int dp[10003][4];
int main()
{
    int qs=0;
    scanf(" %s",a+1);
    scanf(" %s",b+1);
    lena=strlen(a+1);
    lenb=strlen(b+1);
    for(i=0;i<4;i++){
        scanf("%d",&cost[i]);
        qs+=cost[i];
    }
    for(i=0;i<=lena;i++){
        for(j=0;j<4;j++)dp[i][j]=1<<30;
    }
    for(i=lena;i>=0;i--){
        if(a[i+1]=='A'){
            dp[i][0]=i+1;
        }
        if(a[i+1]=='G'){
            dp[i][1]=i+1;
        }
        if(a[i+1]=='C'){
            dp[i][2]=i+1;
        }
        if(a[i+1]=='T'){
            dp[i][3]=i+1;
        }
        dp[i][0]=min(dp[i][0],dp[i+1][0]);
        dp[i][1]=min(dp[i][1],dp[i+1][1]);
        dp[i][2]=min(dp[i][2],dp[i+1][2]);
        dp[i][3]=min(dp[i][3],dp[i+1][3]);
    }
    now=0;
    for(i=1;i<=lenb;i++){
        cou=0;
        for(j=i;j<=lenb;j++){
            now=dp[now][b[j]];
            cou++;
        }

    }
    return 0;
}
