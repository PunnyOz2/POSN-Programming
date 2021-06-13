/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long a[1010];
int main()
{
    long long n,num,i,j,ans=0;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&num);
        a[num]++;
    }
    for(i=0;i<=999;i++){
        for(j=i;j<=999;j++){
            if(i==j)ans+=a[i]*(a[i]-1)/2;
            else if((j/100)==(i/100) || ((j%100)/10)==((i%100)/10) || (j%10)==(i%10))ans+=a[i]*a[j];
        }
    }
    printf("%lld\n",ans);
    return 0;
}
/*

*/
