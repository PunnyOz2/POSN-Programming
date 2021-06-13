/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long dp1[100100],dp2[100100],dp3[100100];
int main()
{
    long long n,k,i,sum;
    scanf("%lld %lld",&n,&k);
    if(k==-1){printf("0\n");return 0;}
    if(k==0){printf("1\n");return 0;}
    dp1[0]=1;
    for(i=1;i<=n;i++){
        dp1[i]=(dp1[i-1]+dp2[i-1]+dp3[i-1])%1000000007;
        if(i>=k)dp3[i]=dp1[i-k];
        dp2[i]=((dp1[i-1]+dp2[i-1]-dp3[i]+1000000007)%1000000007)%1000000007;
    }
    sum=(dp1[n]+dp2[n]+dp3[n])%1000000007;
    k--;
    if(k==-1){
        sum-=0;
    }
    else if(k==0){
        sum-=1;
    }
    else{
        memset(dp1,0,sizeof dp1);
        memset(dp2,0,sizeof dp2);
        memset(dp3,0,sizeof dp3);
        dp1[0]=1;
        for(i=1;i<=n;i++){
            dp1[i]=(dp1[i-1]+dp2[i-1]+dp3[i-1])%1000000007;
            if(i>=k)dp3[i]=dp1[i-k];
            dp2[i]=((dp1[i-1]+dp2[i-1]-dp3[i]+1000000007)%1000000007)%1000000007;
        }
        sum-=(dp1[n]+dp2[n]+dp3[n])%1000000007;
    }
    printf("%lld\n",(sum+1000000007)%1000000007);
    return 0;
}
