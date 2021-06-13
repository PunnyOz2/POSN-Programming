/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long a[200100];
int main()
{
    long long n,Min=1e9,idxi=1,idxj,Max=-1e9,i,ii,jj,sum;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        a[i]+=a[i-1];
    }
    for(i=1;i<=n;i++){
        if(Min>a[i-1]){
            Min=a[i-1];
            idxi=i;
        }
        sum=a[i]-Min;
        if(sum>Max){
            Max=sum;
            ii=idxi;
            jj=i;
        }
    }
    printf("%lld %lld \n%lld",ii,jj,Max);
    return 0;
}
/*
5
4 -6 3 -2 6
4 -2 1 -1 5
*/
