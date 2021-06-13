/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long mic[2100][5000],a[2010];
long long play(long long n,long long k){
    if(mic[n][k])return mic[n][k];
    if(n==0 && k!=0)return -1e9;
    if(n==0)return 0;
    if(k==0){
        return mic[n][k]=max(play(n-1,k),play(n-1,k+2)-a[n]);
    }
    return mic[n][k] = max(play(n-1,k-1)+a[n],play(n-1,k+2)-a[n]);
}
int main()
{
    long long n,i;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    printf("%lld\n",play(n,0));
    return 0;
}
/*
7
1 2 3 4 5 6 7
*/
