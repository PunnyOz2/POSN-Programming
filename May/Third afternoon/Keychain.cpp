/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100100];
long long qs[100100];
int main()
{
    long long ans=0;
    long long n,k,num,i;
    scanf("%lld %lld",&n,&k);
    for(i=1;i<=n;i++){
        scanf("%lld",&num);
        a[num]=i;
    }
    ans+=a[1]-1;
    k--;
    for(i=1;i<n;i++){
        if(a[i+1]-a[i]>=0){
            qs[i]=a[i+1]-a[i];
        }
        else{
            qs[i]=n-a[i]+a[i+1];
        }
    }
    if(a[1]-a[n]>=0){
        qs[n]=a[1]-a[n];
    }
    else{
        qs[n]=n+a[1]-a[n];
    }
    for(i=1;i<=n;i++){
        qs[i]+=qs[i-1];
    }
    ans+=(k/n*qs[n]);
    if(k%n!=0){
        ans+=qs[(k%n)];
    }
    printf("%lld\n",ans);
    return 0;
}
/*
4 9
4 2 1 3
*/
