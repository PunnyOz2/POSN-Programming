/*
    TASK: Loose sum
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dp[2100];
int main()
{
    int i,j,q;
    dp[0]=1;
    for(i=1;i<=2000;i++)
        for(j=2000;j>=i;j--)
            dp[j]+=dp[j-i],dp[j]%=1000003;
        scanf("%d",&q);
        while(q--){
            scanf("%d",&i);
            printf("%d\n",dp[i]);
        }

    return 0;
}
/*

*/
