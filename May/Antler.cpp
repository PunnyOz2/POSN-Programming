/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long cnt[2000003];
int main()
{
    long long i,num,n,j,ans=0,sum;
    scanf("%lld",&n);
    for(i=0;i<n;i++){
        scanf("%lld",&j);
        cnt[j]++;
    }
    for(i=1;i<=2000000;i++){
        for(j=i,sum=0;j<=2000000;j+=i)
            sum+=cnt[j];
        if(sum>=2)ans=max(ans,sum*i);
    }
    printf("%lld\n",ans);
    return 0;
}
