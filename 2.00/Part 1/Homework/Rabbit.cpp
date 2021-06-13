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
    long long n,s,l,r,num,mid,i,j,num2;
    scanf("%lld %lld",&n,&s);
    l=0,r=n+1;
    while(l<r){
        mid=(l+r)/2;
        num=mid;
        num2=num;
        while(num2!=0){
            num-=num2%10;
            num2/=10;
        }
        if(num<s) l=mid+1;
        else r=mid;
    }
    if(n<l) printf("0\n-1");
    else printf("%lld\n%lld",n-l+1,n);
    return 0;
}
/*
12 1
*/
