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
    long long n,l,r,i,mark=0,markk,pos;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    l=0;
    r=1ll<<31;
    while(l<r){
        long long mid=(l+r)/2;
        mark=0;
        markk=0;
        //printf("%lld\n",mid);
        for(i=1;i<=n;i++){
            if(mid>=a[i])continue;
            if(mark==0){
                mark=1;
                pos=i;
            }
            else if(mark==1){
                if(a[i]==a[pos]){
                    mark=0;
                }
                else{
                    markk=1;
                    break;
                }
            }
        }
        if(markk==0)r=mid;
        else{
            l=mid+1;
        }
    }
    printf("%d\n",l);
    return 0;
}
/*
6
3 5 2 2 5 3
*/
