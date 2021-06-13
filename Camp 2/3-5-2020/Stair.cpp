/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dp[5500];
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=n;j>=1;j--){
            dp[j]+=dp[j-i];
        }
    }
    dp[n]--;
    printf("%d\n",dp[n]%k);
    return 0;
}
