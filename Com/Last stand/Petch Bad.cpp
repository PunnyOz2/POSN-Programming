/*
    TASK: Swift wood cut
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long a[500100];
int main()
{
    long long n,b,l,r,mid,i,sum;
    scanf("%lld %lld",&n,&b);
    for(i=0;i<n;i++)
        scanf("%lld",&a[i]);
    l=0,r=200000000000;
    while(l<r){
        mid = (l+r)/2;
        for(i=0,sum=0;i<n;i++){
            sum+=(a[i]/mid);
            if(a[i]%mid!=0) sum++;
        }
        if(sum<=b) r=mid;
        else l=mid+1;
    }
    printf("%lld",l);
    return 0;
}
/*

*/
