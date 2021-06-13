/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100100];
long long lis[100100];
int main()
{
    long long n,cnt=0,idx,i;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        a[i]+=a[i-1];
    }
    for(i=1;i<=n;i++){
        if(i!=n && a[i]>=a[n]){
            continue;
        }
        if(a[i]<=0)continue;
        idx=lower_bound(lis,lis+cnt,a[i])-lis;
        if(idx==cnt)cnt++;
        lis[idx]=a[i];
    }
    printf("%lld\n",cnt);
    return 0;
}
