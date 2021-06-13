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
    long long n,i,cou=0,sum=0;
    scanf("%lld",&n);
    for(i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a,a+n);
    for(i=n-1;i>=0;i--){
        if(cou==2){cou=0;continue;}
        sum+=a[i];
        cou++;
    }
    printf("%lld\n",sum);
    return 0;
}
