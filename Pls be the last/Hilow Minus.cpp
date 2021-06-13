/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
deque<pair<long long,long long>>Min;
long long a[1000100];
int main()
{
    long long n,m,i,k;
    scanf("%lld %lld",&n,&m);
    k=n-m;
    for(i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    long long Min2=1<<30;
//    Min.push_back({abs(a[i]-a[i-1]),i});
    for(i=1;i<=n;i++){//i-Min.front().second>n-m
        while(!Min.empty() && i-Min.front().second>=k-1)Min.pop_front();
        while(!Min.empty() && Min.back().first>=a[i]-a[i-1])Min.pop_back();
        Min.push_back({a[i]-a[i-1],i});
        if(i<k)continue;
//        printf("%d %d %d\n",Min.front().first,a[i],a[i-k+1]);
        Min2=min(Min2,Min.front().first+a[i]-a[i-k+1]);
    }
    printf("%lld\n",Min2);
    return 0;
}
/*
6 2
9 7 -4 1 12 -2
*/
