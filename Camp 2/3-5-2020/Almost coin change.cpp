/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dp[2000100];
int main()
{
    int n,m,k,i,num,j;
    scanf("%d %d %d",&n,&m,&k);
    for(i=1;i<=m+k+1;i++){
        dp[i]=1<<30;
    }
    for(i=1;i<=n;i++){
        scanf("%d",&num);
        for(j=num;j<=m+k+1;j++){
            dp[j]=min(dp[j],dp[j-num]+1);
        }
    }
    int Min=1<<30,idx,ans;
    for(i=m;i<=m+k;i++){
        if(Min>dp[i])Min=dp[i],idx=i;
    }
    if(Min==1<<30)printf("-1\n");
    else printf("%d\n%d\n",Min,idx-m);
    return 0;
}
/*
3 12 5
1 3 5
*/
