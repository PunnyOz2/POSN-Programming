/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100100];
int main()
{
    long long n,i,sum=0;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(i==1){sum+=a[i]-1;continue;}
        sum+=a[i]-__gcd(a[i],a[i-1]);
    }
    printf("%lld\n",sum);
    return 0;
}
/*
6
4
2
3
3
6
2
*/
