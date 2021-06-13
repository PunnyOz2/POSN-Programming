#include<bits/stdc++.h>
#define x second
#define y first
using namespace std;
pair<long long,long long> a[100100];
long long fw[100100];
void update(long long i){
    while(i<=100003){
        fw[i]++;
        i+=(i&-i);
    }
}
long long query(long long i){
    long long sum=0;
    while(i>0){
        sum+=fw[i];
        i-=(i&-i);
    }
    return sum;
}
long long ans[100100];
int main(){
    long long n,i,sum=0;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld %lld",&a[i].x,&a[i].y);
    }
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++){
        ans[i]=query(100001-a[i].x);
        update(100001-a[i].x);
    }
    memset(fw,0,sizeof fw);
    for(i=n;i>=1;i--){
        ans[i]+=query(a[i].x);
        update(a[i].x);
    }
    for(i=1;i<=n;i++){
        sum+=ans[i]*a[i].x;
    }
    printf("%lld\n",sum);
    return 0;
}
/*
6
2 1
7 6
9 3
18 4
3 2
5 5

6
2 1
3 2
9 3
18 4
5 5
7 6
*/
