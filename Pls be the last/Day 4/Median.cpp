/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long fw[1000100];
long long query(long long a){
    long long sum=0;
    while(a>0){
        sum+=fw[a];
        a-=(a&-a);
    }
    return sum;
}
void update(long long a){
    while(a<1000003){
        fw[a]+=1;
        a+=(a&-a);
    }
}
long long qs[100100];
int main()
{
    long long n,k,i,now;
    scanf("%lld %lld",&n,&k);
    for(i=1;i<=n;i++){
        scanf("%lld",&now);
        if(now>=k)qs[i]=1;
        else qs[i]=-1;
    }
    long long ans=0;
    update(100000);
    for(i=1;i<=n;i++){
        qs[i]+=qs[i-1];
        ans+=query(qs[i]+100000);
        update(qs[i]+100000);
    }
    printf("%lld\n",ans);
    return 0;
}
