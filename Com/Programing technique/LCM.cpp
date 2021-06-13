/*
    TASK:
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<stdio.h>
long long gcd(long long a,long long b){
    if(a%b==0) return b;
    return gcd(b,a%b);
}
int main()
{
    long long n,i,ans,now;
    scanf("%lld %lld",&n,&ans);
    for(i=0;i<n-1;i++){
        scanf("%lld",&now);
        ans = ans*now/gcd(ans,now);
    }
    printf("%lld\n",ans);


    return 0;
}
