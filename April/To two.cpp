/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[50];
long long swift[45];
long long cal(long long a){
    long long ans=2*(a-a/2-1);
    for(long long i=2;i<41;i++){
        ans+=(swift[i+1]+1)*(a/dp[i]-a/dp[i+1]);
    }
    return ans;
}
long long gcd(long long a,long long b){
    if(a==0)return b;
    if(b==0)return a;
    if(a%b==0)return b;
    return gcd(b,a%b);
}
int main()
{
	long long a,b,i,j;
	scanf("%lld %lld",&a,&b);
	memset(dp,1,sizeof dp);
	dp[1]=1;
	for(i=2;i<=41;i++)
        dp[i]=dp[i-1]*(i/gcd(i,dp[i-1]));
    swift[2]=1;
    for(i=3;i<=41;i++){
        for(j=2;j<=41;j++){
            if(i%j!=0){
                swift[i]=swift[j]+1;
                break;
            }
        }
    }
    printf("%lld",cal(b)-cal(a-1));
    return 0;
}
