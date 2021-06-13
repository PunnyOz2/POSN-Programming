/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100100],n,m,rr,c;
long long play(long long l,long long r){
    long long cou,mid=(l+r)/2;
    if(l==r){
        cou=upper_bound(a+1,a+1+m,r)-lower_bound(a+1,a+1+m,l);
        if(cou==0)return rr;
        return cou*c;
    }
    cou=upper_bound(a+1,a+1+m,r)-lower_bound(a+1,a+1+m,l);
    if(cou==0)return rr;
    return min(c*(r-l+1)*cou,play(l,mid)+play(mid+1,r));
}
int main()
{
    long long q,i;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld %lld %lld",&n,&m,&rr,&c);
        for(i=1;i<=m;i++){
            scanf("%lld",&a[i]);
        }
        sort(a+1,a+1+m);
        printf("%lld\n",play(1,1<<n));
    }
    return 0;
}
/*
3
2 2 1 2
1 3
*/
