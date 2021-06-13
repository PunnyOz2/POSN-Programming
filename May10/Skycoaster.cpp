/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long a[250000],b[250000],dp[250000];
int main()
{
    long long q,n,c,i;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld",&n,&c);
        for(i=0;i<n;i++)scanf("%lld",&a[i]),a[i+n]=a[i];
        for(i=0;i<n;i++)scanf("%lld",&b[i]),b[i+n]=b[i];
        int st=0,ch=0;
        long long force=0;
        for(i=0;i<2*n;i++){
            force=min(c,force+a[i])-b[i];
            if(force<0)st=i+1,force=0;
            if(i-st==n-1){
                ch=1;break;
            }
        }
        if(ch==0){
            printf("0\n");
            continue;
        }
        dp[st]=0;
        long long cou=1;
        for(i=(st-1+n)%n;i!=st;i=(i-1+n)%n){
            long long want=max(0ll,b[i]-min(c,a[i]));
            dp[i]=max(want,dp[(i+1+n)%n]-min(c,a[i])+b[i]);
            if(min(c,a[i])-b[i]>=dp[(i+1+n)%n])cou++;
        }
        printf("%lld\n",cou);
    }
    return 0;
}
/*
2
3 3
3 1 2
2 2 2
3 3
3 1 2
2 2 2
*/
