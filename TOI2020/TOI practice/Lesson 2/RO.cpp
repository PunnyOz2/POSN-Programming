#include<bits/stdc++.h>
using namespace std;
char a;
long long dp[1000100];
map<long long,long long> mp;
int main(){
    long long n,k,i,Max=0;
    scanf("%lld %lld",&n,&k);
    for(i=1;i<=n;i++){
        dp[i]=dp[i-1];
        scanf(" %c",&a);
        if(a=='R')dp[i]-=k;
        else dp[i]++;
        if(mp[dp[i]]==0)mp[dp[i]]=i;
        else Max=max(Max,i-mp[dp[i]]);
    }
    printf("%lld\n",Max);
    return 0;
}
/*
15 3
RORROOROOROOORO
17 3
OROOOOOROOOOORRRR
*/
