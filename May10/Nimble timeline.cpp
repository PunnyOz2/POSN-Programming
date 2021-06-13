/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long a[500100];
struct A{
    long long x,y,idx;
    bool operator<(const A&o)const{
        return x<o.x;
    }
};
A b[500100];
long long fw[1000100];
long long ans[500100];
void update(long long a,long long b){
    long long i;
    for( i=a ; i<=1000000 ; i+=(i&-i) ){
        fw[i]+=b;
    }
}
long long query(long long a){
    long long sum=0;
    while(a>0){
        sum+=fw[a];
        a-=(a&-a);
    }
    return sum;
}
int main()
{
    long long n,m,i,l,r,mid;
    scanf("%lld %lld",&n,&m);
    for(i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(i=1;i<=m;i++)scanf("%lld %lld",&b[i].x,&b[i].y),b[i].idx=i;
    sort(b+1,b+1+m);
    int ptr=1;
    for(i=1;i<=m;i++){
        while(ptr<=b[i].x){
            update(a[ptr++],1);
        }
        l=1,r=1e6+5;
        while(l<r){
            mid=(l+r)/2;
            if(query(mid)<b[i].y)l=mid+1;
            else r=mid;
        }
        ans[b[i].idx]=l;
    }
    for(i=1;i<=m;i++)printf("%lld\n",ans[i]);
    return 0;
}
/*
7 3
3 5 6 4 2 5 7
5 3
7 5
3 2
*/
