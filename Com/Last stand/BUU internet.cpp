/*
    TASK: Swift wood cut
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long a[110];
int main()
{
    long long i,m,n,l,r,mid,sum,Max=0,coun;
    scanf("%lld %lld",&m,&n);
    for(i=0;i<n;i++){
        scanf("%lld",&a[i]);
        Max= max(Max,a[i]);
    }
    l=Max,r=1<<30;
    while(l<r){
        mid = (l+r)/2;
        sum=0,coun=1;
        for(i=0;i<n;i++){
            if(sum+a[i]>mid)
                coun++,sum=a[i];
            else sum+=a[i];
        }
        if(coun<=m) r=mid;
        else l=mid+1;
    }
    printf("%lld",l);
    return 0;
}
/*
3 4
800
400
400
700
*/
