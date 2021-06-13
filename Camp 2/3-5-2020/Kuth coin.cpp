/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[5]={1,5,10,25,50};
int dp[100100];
int main()
{
    int q,n,i,j;
    dp[0]=1;
    for(i=0;i<5;i++){
        for(j=a[i];j<=100000;j++)dp[j]+=dp[j-a[i]],dp[j]%=1000003;
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        printf("%d\n",dp[n]);
    }
    return 0;
}
