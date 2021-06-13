/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
struct A{
    long long a[202][202];
};
A temp;
void mul(A *a,A *b){
    memset(temp.a,0,sizeof temp.a);
    for(long long i=0;i<202;i++){
        for(long long j=0;j<202;j++){
            for(long long k=0;k<202;k++){
                temp.a[i][j]+=a->a[i][k]*b->a[k][j];
                temp.a[i][j]%=mod;
            }
        }
    }
}
A dp[30],ans;
int main()
{
    long long i,n,k,j;
    dp[0].a[0][0]=1;
    for(i=1;i<=200;i++){
        dp[0].a[i][0]=1;
        for(j=1;j<=i;j++)
            dp[0].a[i][j]=(dp[0].a[i-1][j]+dp[0].a[i-1][j-1])%mod;
    }
    scanf("%lld %lld",&n,&k);
    dp[0].a[201][201]=dp[0].a[201][k]=1;
    for(i=1;i<30;i++){
        mul(&dp[i-1],&dp[i-1]);
        dp[i]=temp;
    }
    for(i=0;i<=200;i++)
        ans.a[i][0]=1;
    for(i=0;i<30;i++){
        if(n&(1ll<<i)){
            mul(&dp[i],&ans);
            ans=temp;
        }
    }
    printf("%lld",ans.a[201][0]);
    return 0;
}
// 2 3
