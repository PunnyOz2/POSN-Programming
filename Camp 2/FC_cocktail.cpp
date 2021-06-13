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
    long long n,i,num,k,sum=0;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&num);
        a[num]++;
    }
    scanf("%lld",&k);
    for(i=0;i<=k/2;i++){
        if(a[i]==0 || a[k-i]==0)continue;
        if(i==k-i)sum+=(a[i]*(a[i]-1))/2;
        else sum+=a[i]*a[k-i];
        a[i]=a[k-i]=0;
    }
    printf("%lld\n",sum);
    return 0;
}
/*

*/
