/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long a[2000100];
int main()
{
    long long n,i,l,r,mid,last,idx,ch;
    scanf("%lld",&n);
    for(i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    l=0,r=(1ll<<31);
    while(l<r){
        mid=(l+r)/2;
        idx=0;
        last=-1;
        ch=1;
        while(idx<n){
            if(a[idx]<=mid)idx++;
            else if(a[idx]==last)idx++,last=-1;
            else if(last==-1){
                last=a[idx];
                idx++;
            }
            else{
                ch=0;
                break;
            }
        }
        if(ch==0)
            l=mid+1;
        else r=mid;
    }
    printf("%lld\n",l);
    return 0;
}
/*
6
3
5
2
2
5
3
*/
