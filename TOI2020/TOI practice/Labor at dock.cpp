/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long a[1000010];
int main(){
    long long n,m,i,mid,l,r,temp;
    scanf("%lld %lld",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    l=1;
    r=1e18;
    while(l<r){
        mid=(l+r)/2;
        temp=0;
        for(i=1;i<=n;i++){
            temp+=mid/a[i];
        }
        if(temp>=m)r=mid;
        else l=mid+1;
    }
    printf("%lld\n",l);
    return 0;
}
/*
*/
