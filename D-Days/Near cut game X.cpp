/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100100];
long long dp[100100];
int main()
{
    long long Q,Max,i,n,num,ans;
    scanf("%lld",&Q);
    while(Q--){
        ans=0;
        Max=-1;
        scanf("%lld",&n);
        for(i=0;i<n;i++){
            scanf("%lld",&num);
            a[num]+=num;
            Max=max(Max,num);
        }
        dp[0]=0;
        dp[1]=a[1];
        for(i=2;i<=Max;i++){
            dp[i]=max(dp[i-2]+a[i],dp[i-1]);
        }
        printf("%lld\n",dp[Max]);
        for(i=1;i<=Max;i++)a[i]=dp[i]=0;
    }
    return 0;
}
/*
3
2
3 4
3
7 6 5
10
1 2 1 2 3 1 2 1 2 1
*/
