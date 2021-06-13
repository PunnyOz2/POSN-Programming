/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000100],dp[1000100];
int main()
{
    int n,num,Max=0,i,idx;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        idx=upper_bound(dp,dp+Max,a[i])-dp;
        if(idx == Max)  Max++;
        dp[idx] = a[i];
    }
    printf("%d\n",n-Max);
    return 0;
}
/*
4
5 4 3 6
*/
