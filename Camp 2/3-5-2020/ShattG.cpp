/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long a[1000100],b[1000100];
int main()
{
    long long n,i,l,r,num,cou;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(i=1;i<=n;i++){
        scanf("%lld",&b[i]);
    }
    scanf("%lld",&num);
    l=0,r=1000001;
    while(l<r){
        long long mid=(l+r+1)/2;
        cou=0;
        for(i=1;i<=n;i++){
            if(a[i]*mid-b[i]<0)cou+=0;
            else cou+=a[i]*mid-b[i];
        }
        if(cou>num){
            r=mid-1;
        }
        else{
            l=mid;
        }
    }
    printf("%lld\n",l);
    return 0;
}
