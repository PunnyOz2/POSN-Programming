//Tawatwee
#include<bits/stdc++.h>
using namespace std;
long long a[201000],b[200100],qs[200100];
int main()
{
    long long n,m,i,j,ch1,ch2;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        qs[i]+=qs[i-1]+a[i];
    }
    for(i=n;i>=1;i--){
        b[i]+=b[i+1]+a[i];
    }
    long long sum=0,Max=-1;
    if(n<=5){
        for(i=2;i<n;i++){
            if(a[i-1]!=0 && a[i]!=0 && a[i+1]!=0 && min(a[i],min(a[i+1]-1,a[i-1]))!=0)
                Max=max(Max,qs[i-1]+min(a[i],min(a[i+1]-1,a[i-1]))+b[i+1]);
        }
        if(Max==0)printf("-1\n");
        else printf("%lld\n",Max);
        return 0;
    }
    for(i=2;i<n;i++){
        if(a[i-1]!=0 && a[i]!=0 && a[i+1]!=0 && min(a[i],min(a[i+1]-1,a[i-1]-1))!=0)
            Max=max(Max,qs[i-1]+min(a[i],min(a[i+1]-1,a[i-1]-1))+b[i+1]);
    }
    if(Max==-1)printf("-1\n");
    else printf("%lld\n",Max);
    return 0;
}
/*
5
3 2 1 2 3
*/
