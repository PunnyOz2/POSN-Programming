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
    long long i,temp,cou,l,r,n,m;
    scanf("%lld %lld",&n,&m);
    l=0,r=n+1;
    while(l<r){
        long long mid=(l+r)/2;
        temp=mid;
        cou=0;
        while(temp>0){
            cou+=temp%10;
            temp/=10;
        }
        if(mid-cou>=m)r=mid;
        else l=mid+1;
    }
    if(n<l)printf("0\n-1\n");
    else printf("%lld\n%lld",n-l+1,n);
//    for(i=990;i<=1010;i++){
//        temp=i;
//        cou=0;
//        while(temp>0){
//            cou+=temp%10;
//            temp/=10;
//        }
//        printf("%d %d\n",i,i-cou);
//    }
    return 0;
}
