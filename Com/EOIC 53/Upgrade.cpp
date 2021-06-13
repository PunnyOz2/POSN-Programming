/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long sum,q,i,n,m,mod,ans;
    scanf("%lld",&q);
    while(q--){
        sum=0;
        ans=1;
        scanf("%lld %lld %lld",&n,&m,&mod);
        sum=n/2*(n+1);
        for(i=1;i<=m;i++){
            ans*=sum;
            ans%=mod;
        }
        printf("%lld\n",ans%mod);
    }

    return 0;
}
