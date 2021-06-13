/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,m,i=0;
    scanf("%lld %lld",&n,&m);
    printf("%lld",m-__gcd(n,m));
    return 0;
}
