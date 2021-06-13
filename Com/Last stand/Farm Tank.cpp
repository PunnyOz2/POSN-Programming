/*
    TASK: Ant
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main()
{
    long long n,m,mid,l,r,i,sum;
    scanf("%lld %lld",&n,&m);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    l=0,r=200000000000000000;
    while(l<r){
        mid = (l+r)/2;
        for(i=0,sum=0;i<n;i++)
            sum+= mid/a[i];
        if(sum>=m) r=mid;
        else l=mid+1;
    }
    printf("%lld",l);

    return 0;
}

