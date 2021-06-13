/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long st[100100];
long long qs[100100];
int main()
{
    long long n,com,q,i,a,b,c,idx,idx2;
    scanf("%lld %lld %lld",&n,&com,&q);
    for(i=1;i<=n;i++){
        scanf("%lld",&st[i]);
    }
    while(com--){
        scanf("%lld %lld %lld",&a,&b,&c);
        idx=upper_bound(st+1,st+1+n,a)-st;
        idx2=upper_bound(st+1,st+1+n,b)-st;
        idx--;
        idx2--;
        qs[idx]+=c;
        qs[idx]%=99877;
        qs[idx2+1]-=c;
        qs[idx2+1]%=99877;
    }
    for(i=1;i<=n;i++){
        qs[i]+=qs[i-1];
        qs[i]%=99877;
    }
    for(i=1;i<=n;i++){
        qs[i]+=qs[i-1];
        qs[i]%=99877;
    }
    while(q--){
        scanf("%lld %lld",&a,&b);
        idx=upper_bound(st+1,st+1+n,a)-st;
        idx2=upper_bound(st+1,st+1+n,b)-st;
        idx--;
        idx2--;
        printf("%lld\n",(qs[idx2]-qs[idx-1]+99877+99877)%99877);
    }
    return 0;
}
