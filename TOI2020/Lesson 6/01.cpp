#include<bits/stdc++.h>
using namespace std;
struct A{
    long long nn,pos;
    bool operator<(const A&o)const{
        return pos<o.pos;
    }
};
A a[500100];
long long qs[500100],qsn[500100];
int main(){
    long long n,i,now,temp,temp2,Min=1e18,ans,Minn=1e18;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i].nn);
        Minn=min(Minn,a[i].nn);
    }
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i].pos);
    }
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++){
        qsn[i]=qsn[i-1]+a[i].nn;
        qs[i]=qs[i-1]+a[i].pos;
    }
    for(i=1;i<=n;i++){
        now=a[i].pos;
        if(now>Minn)break;
        temp=qsn[i-1]+qs[i-1]-a[i].pos*(i-1);
        temp2=qs[n]-qs[i]-a[i].pos*(n-i);
        if(Min>temp+temp2){
            Min=temp+temp2;
            ans=now;
        }
    }
    printf("%lld %lld\n",ans,Min);
    return 0;
}
/*

*/
