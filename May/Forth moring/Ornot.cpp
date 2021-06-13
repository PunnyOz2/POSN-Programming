/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char s[1200100];
int dp[2400101];
int main()
{
    int n,sum,ans,i;
    scanf("%d %s",&n,s);
    sum=0,ans=0;
    dp[n]=1;
    for(i=0;i<n;i++){
        if(s[i]=='1')sum++;
        else sum--;
        ans+=dp[sum+n];
        dp[sum+n]++;
        ans%=10007;
    }
    printf("%d",ans);
    return 0;
}
