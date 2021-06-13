/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long a[2000100];
int main()
{
    long long l,r,Max=0,i,ch,n,mid,old;
    scanf("%lld",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        Max=max(Max,a[i]);
    }
    old=0;
        for(i=0;i<n;i++){
            if(old==a[i])old=0;
            else if(old==0)old=a[i];
            else {ch=1;break;}
        }
    if(ch==1){
    l=1,r=Max+1;
    while(l<r){
        ch=0;
        mid=(l+r)/2;
        old=0;
        for(i=0;i<n;i++){
            if(old==a[i])old=0;
            else if(a[i]>mid && old==0)old=a[i];
            else if(a[i]<=mid)continue;
            else {ch=1;break;}
        }
        if(ch)l=mid+1;
        else r=mid;
    }
    printf("%lld",l);
    }
    else printf("0");
    return 0;
}
/*
6
3
3
2
5
5
2
*/
