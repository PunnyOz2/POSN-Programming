/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dp[100100];
int main()
{
    int n,m,q,s,e,v,b,i;
    scanf("%d %d %d",&n,&m,&q);
    while(m--){
        scanf("%d %d %d",&s,&e,&v);
        dp[s]+=v,dp[e+1]-=v;
    }
    for(i=1;i<=n;i++)
        dp[i]+=dp[i-1];
    while(q--){
        scanf("%d",&b);
        printf("%d\n",dp[b]);
    }


    return 0;
}
/*
5 3 1
1 3 5
2 5 4
2 4 1
3
*/
