/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long c;
long long play(long long a,long long b){
    //if(dp[a][b]!=-1)return dp[a][b];
    if(b==1)return a%c;
    int t=play(a,b/2);
    if(b%2==1)return ((t%c)*(t%c)*(a%c))%c;
    return ((t%c)*(t%c))%c;
}
int main()
{
    long long q,a,b;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld %lld",&a,&b,&c);
        printf("%lld\n",play(a,b));
    }
    return 0;
}
/*

*/
