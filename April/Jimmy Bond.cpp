/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
double dp[2100000];
int n,a[25][25];
double play(int bit){
    if(bit==0)return 1;
    if(dp[bit]!=-1)return dp[bit];
    int cou=0,cou2=0,i;
    double Max=-1;
    int have[23],dont[23];
    for(i=0;i<n;i++){
        if(bit&(1<<i))have[cou++]=i;
        else dont[cou2++]=i;
    }
    for(i=0;i<cou;i++)if(Max-play(bit^(1<<have[i]))*a[cou-1][have[i]]/100<1e-6)Max=play(bit^(1<<have[i]))*a[cou-1][have[i]]/100;
    return dp[bit]=Max;
}
int main()
{
    int i,j;
	scanf("%d",&n);
	for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)a[i][j]=1;
    for(i=0;i<=1<<n;i++)dp[i]=-1;
	for(i=0;i<n;i++)
        for(j=0;j<n;j++)scanf("%d",&a[i][j]);
    double ans=play((1<<n)-1)/(pow(100,n-1))*pow(100,n);
    printf("%.2lf\n",ans);
    return 0;
}
/*
2
100 100
50 50
*/
