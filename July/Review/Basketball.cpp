/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100100][2];
int main()
{
    long long n,i;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i][0]);
    }
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i][1]);
    }
    for(i=2;i<=n;i++){
        //team1
        a[i][0]+=max(a[i-2][0],max(a[i-2][1],a[i-1][1]));
        //team2
        a[i][1]+=max(a[i-2][1],max(a[i-2][0],a[i-1][0]));
    }
    printf("%lld\n",max(a[n][0],a[n][1]));
    return 0;
}
