/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long fw[1000003],cnt=0,fw2[1000003];
void update(long long a,long long b){
    long long i;
    for(i=a;i<=1000003;i+=(i&-i)){
        fw[i]+=b;
    }
}
long long query(long long a){
    long long sum=0,i;
    for(i=a-1;i>0;i-=(i&-i)){
        sum+=fw[i];
    }
    return sum;
}
void update2(long long a,long long b){
    long long i;
    for(i=a;i<=1000003;i+=(i&-i)){
        fw2[i]+=b;
    }
}
long long query2(long long a){
    long long sum=0,i;
    for(i=a-1;i>0;i-=(i&-i)){
        sum+=fw2[i];
    }
    return sum;
}
long long a[100100];
int main()
{
    long long q,ans=0,n,i;
    scanf("%lld",&q);
    while(q--){
        ans=0;
        scanf("%lld",&n);
        for(i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        for(i=n;i>0;i--){
            cnt=0;
            ans+=query(a[i]);
            ans+=query2(a[i])*a[i];
            update(a[i],a[i]);
            update2(a[i],1);
        }
        printf("%lld\n",ans);
        memset(fw,0,sizeof fw);
        memset(fw2,0,sizeof fw);
    }
    return 0;
}
/*
2
5
1 2 3 5 4
5
5 4 3 2 1
*/
