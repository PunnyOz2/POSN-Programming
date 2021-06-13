/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long len(long long n){
    if(n==1)return 1;
    if(n==0)return 1;
    return len(n/2)*2+len(n%2);
}
long long n,l,r;
long long play(long long n,long long ll,long long rr){
    if(rr<l || ll>r)return 0;
    if(n==1)return 1;
    if(n==0)return 0;
    long long mid=(ll+rr)/2,cou=0;
    cou+=play(n/2,ll,mid-1);
    cou+=play(n/2,mid+1,rr);
    if(n%2==1)cou+=play(1,mid,mid);
    else cou+=play(0,mid,mid);
    return cou;
}
int main()
{
    scanf("%lld %lld %lld",&n,&l,&r);
    long long nn=len(n);
    //printf("%lld\n",nn);
    printf("%lld",play(n,1,nn));
    return 0;
}
/*

*/
