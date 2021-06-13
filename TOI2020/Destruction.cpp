#include<bits/stdc++.h>
using namespace std;
long long qs[50100],dp[50100][3];
int main(){
    long long n,k,m,i,j,mi;
    scanf("%lld %lld %lld",&n,&k,&m);//number of punches // Minimum destroyed
    for(i=1;i<=n;i++){
        scanf("%lld",&qs[i]);
        qs[i]+=qs[i-1];
    }
    for(i=1;i<=k;i++){
        mi=1e18;
        for(j=i*m+i-1;j<=n;j++){
            mi=min(mi,-qs[j-m]+(dp[max(0ll,j-m-1)][(i-1)%2]));
            dp[j][i%2]=qs[j]+mi;
            if(j!=i*m+i-1)dp[j][i%2]=min(dp[j][i%2],dp[j-1][i%2]);
        }
    }
    printf("%lld\n",qs[n]-dp[n][k%2]);
    return 0;
}
/*
7 1 3
1 0 4 8 5 7 6

*/
