/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[300100],c[300100],b[300100];
int main()
{
    int n,i,now,l,r,sum,mid;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        c[i]=a[i];
    }
    sort(a+1,a+1+n,greater<int>());
    for(i=1;i<=n;i++){
        b[i]+=b[i-1]+a[i];
    }
    for(i=1;i<=n;i++){
        now=c[i];
        l=1,r=n;
        while(l<r){
            mid=(l+r)/2;
            if(a[mid]<now)sum=b[mid]-now;
            else sum=b[mid];
            if(sum+now>(b[n]/2))r=mid;
            else l=mid+1;
        }
        if(a[l]<now)printf("%d\n",l-1);
        else printf("%d\n",l);
    }
    return 0;
}
/*
5
7 1 1 2 3

7
5 5 6 7 5 5 8
*/
