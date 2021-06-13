/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
map<double,long long>mp;
long long fin3(long long n)
{
    return ((n*(n-1)*(n-2))/6)%mod;
}
long long fin2(long long n)
{
    return ((n*(n-1))/2)%mod;
}
int main()
{
    long long n,i;
    double a,b,c;
    scanf("%lld",&n);
    for(i=0;i<n;i++){
        scanf("%lf %lf %lf",&a,&b,&c);
        if(a==0)              mp[1e12]++;
        else mp[-b/a]++;
    }
    long long ans=fin3(n),now;
    for(auto x:mp){
        if(x.second>=2){
            now=fin2(x.second)*(n-x.second);
            ans-=now;
            ans%=mod;
            ans+=mod;
            ans%=mod;
        }
        if(x.second>=3){
            now=fin3(x.second);
            ans-=now;
            ans%=mod;
            ans+=mod;
            ans%=mod;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
/*
6
0 1 0
0 1 -3
0 1 -2
-5 3 0
-5 -2 25
-4 -5 29
*/
