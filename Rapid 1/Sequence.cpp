#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long dp[500100],po[500100];
long long modofpow(long long a,long long b){
    if(b==1)return a;
    long long PO=(modofpow(a,b/2))%MOD;
    if(b%2==0){
        return (PO*PO)%MOD;
    }
    else{
        return (((PO*PO)%MOD)*a)%MOD;
    }
}
int main()
{
	long long n,p,k,i,j;
	scanf("%lld %lld %lld",&n,&p,&k);
	for(i=p;i>=1;i--){
        if(po[p/i]!=0) dp[i]=po[p/i];
        else po[p/i]=dp[i]=modofpow(p/i,n);
        for(j=2*i;j<=p;j+=i)
            dp[i]=((dp[i]-dp[j])%MOD+MOD)%MOD;
	}
	printf("%lld\n",dp[k]);
    return 0;
}
