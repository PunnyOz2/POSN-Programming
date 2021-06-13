/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long a[5010],b[100100];
long long dp[5010];
int main()
{
    long long n,m,i,j,Min;
    scanf("%lld %lld",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(j=1;j<=m;j++)scanf("%lld",&b[j]);
    Min=1e9;
    for(j=m;j>=1;j--){
        Min=min(Min,b[j]);
        b[j]=Min;
    }
    sort(a+1,a+1+n);
    for(i=1;i<=n;i++){
        dp[i]=1<<30;
        for(j=i;j>=1;j--){
            dp[i]=min(dp[i],dp[j-1]+b[a[i]-a[j]+1]);
        }
    }
    printf("%lld\n",dp[n]);
    return 0;
}
/*
6 12
1 2 11 8 4 12
2 3 4 4 8 9 15 16 17 18 19 19
*/
