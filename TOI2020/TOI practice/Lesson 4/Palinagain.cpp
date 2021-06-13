#include<bits/stdc++.h>
using namespace std;
int dp[5010][5010];
char a[5010],b[5010];
int main(){
    int n,len,i,cou=0,j;
    scanf("%d",&n);
    scanf(" %s",a+1);
    len=strlen(a+1);
    for(i=1;i<=len;i++)b[i]=a[len-i+1];
    for(i=1;i<=len;i++){
        for(j=1;j<=len;j++){
            if(a[i]!=b[j])dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            else dp[i][j]=dp[i-1][j-1]+1;
        }
    }
    printf("%d\n",n-dp[len][len]);
    return 0;
}
/*
5
Ab3bd
*/
