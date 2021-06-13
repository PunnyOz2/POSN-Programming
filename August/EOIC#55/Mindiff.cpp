/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100100];
int main()
{
    long long n,Min=1e18,i;
    scanf("%lld",&n);
    for(i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a,a+n);
    for(i=1;i<n;i++){
            //printf("%d\n",a[i]);
        Min=min(Min,a[i]-a[i-1]);
    }
    printf("%lld\n",Min);
    return 0;
}
/*
10
a 0
a 1
a 2
a 3
a 2
c 4 5
a 5
b 7
b 7
c 9 7
*/
