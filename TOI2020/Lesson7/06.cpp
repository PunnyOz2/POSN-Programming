#include<bits/stdc++.h>
using namespace std;
long long cou[110];
long long dp[110][510];
long long FIND(long long n,long long k){
    long long temp,sum;
    temp=n/(k+1);
    sum=temp*(temp+1)/2*(k+1);
    n%=(k+1);
    sum+=n*(temp+1);
    return sum;
}
int main(){
    long long n,m,k,i,top,sum=0,j,num,l;
    scanf("%lld %lld %lld",&n,&m,&k);
    for(i=1;i<=n;i++){
        scanf("%lld",&num);
        cou[num]++;
    }
    for(i=1;i<=m;i++){
        for(j=0;j<=k;j++){
            dp[i][j]=1<<30;
            for(l=0;l<=j;l++){
                dp[i][j]=min(dp[i][j],dp[i-1][j-l]+FIND(cou[i],l));
            }
        }
    }
    printf("%lld\n",dp[m][k]);
    return 0;
}
/*
10 1 3
1 1 1 1 1 1 1 1 1 1
11 1 3
1 1 1 1 1 1 1 1 1 1 1
*/
