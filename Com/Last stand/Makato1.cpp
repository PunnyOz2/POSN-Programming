/*
    TASK: Makato1
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dp[100100];
int main()
{
    int n,q,i,j;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++){
        scanf("%d",&dp[i]);
        dp[i]^=dp[i-1];
    }
    while(q--){
        scanf("%d %d",&i,&j);
        printf("%d\n",dp[j]^dp[i-1]);
    }
    return 0;
}
/*
5 5
2 6 2 9 1
5 5
1 5
2 3
4 5
2 4
*/
