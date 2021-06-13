/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int qs[500100];
int dp[500100];
int main()
{
    int n,k,i,j,Max=-1;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)scanf("%d",&qs[i]),qs[i]+=qs[i-1];
    if(qs[1]<=k)dp[1]=qs[1];
    for(i=1;i<=n;i++){
        //dp[i]=max(dp[i],dp[i-1]);
        for(j=i;j<=n;j++){
            if(qs[j]-qs[j-i]>k)continue;
            if(i!=j)dp[j]=max(dp[j-i-1]+qs[j]-qs[j-i],dp[j]);
            else dp[j]=max(dp[j],qs[j]-qs[j-i]);
            Max=max(dp[j],Max);
        }
    }
    printf("%d\n",Max);
    return 0;
}
/*
5 5
1 2 3 4 5

5 3
1 2 3 1 2
*/
