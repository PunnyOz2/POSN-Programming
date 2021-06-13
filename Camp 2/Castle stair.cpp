/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100100],qs[100100],up,cou;
int main()
{
    long long q,n,k,i;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld",&n,&k);
        for(i=1;i<=n;i++)scanf("%lld",&a[i]);
        qs[n]=1;
        for(i=n-1;i>=1;i--){
            up=upper_bound(a+1,a+n+1,a[i]+k)-a-1;
            cou=max(qs[i+1]-qs[up+1],0ll);
            if(a[i+1]>a[i]+k)cou=0;
            qs[i]=cou+qs[i+1];
            if(up==i)qs[i]=0;
            qs[i]%=95959;
        }
        printf("%lld\n",max(qs[1]-qs[2],0ll));
        memset(qs,0,sizeof qs);
    }
    return 0;
}
/*
5
5 10
1 3 5 7 9
5 7
1 3 5 7 9

5
4 1
1 2 3 4
*/
