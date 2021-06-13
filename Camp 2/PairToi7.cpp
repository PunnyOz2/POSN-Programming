/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long i,j;
    bool operator<(const A&o)const{
        return j<o.j;
    }
};
A a[100100];
long long cou[100100],sum[100100];
void updatecou(long long i){
    while(i<=100003){
        cou[i]++;
        i+=(i&-i);
    }
}
void updatesum(long long i,long long c){
    while(i<=100003){
        sum[i]+=c;
        i+=(i&-i);
    }
}
long long querycou(long long i){
    long long c=0;
    while(i>0){
        c+=cou[i];
        i-=(i&-i);
    }
    return c;
}
long long querysum(long long i){
    long long c=0;
    while(i>0){
        c+=sum[i];
        i-=(i&-i);
    }
    return c;
}
int main()
{
    long long n,i,ans=0,ii,lowercou,lowersum;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld %lld",&a[i].i,&a[i].j);
    }
    sort(a+1,a+n+1);
    for(i=n;i>=1;i--){
        ii=a[i].i;
        lowercou=querycou(ii);
        lowersum=querysum(ii);
        ans+=lowersum+lowercou*ii;
        updatecou(ii);
        updatesum(ii,ii);
    }
    printf("%lld\n",ans);
    return 0;
}
/*
6
2 1 7 6 9 3 18 4 3 2 5 5

4
1 4 3 2 2 3 7 1
*/
