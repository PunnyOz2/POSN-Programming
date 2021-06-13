/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
#define Mod 1000000007
long long dp[2][10100];
long long a[10100];
int main()
{
	long long n,i,j;
	scanf("%lld",&n);
	for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
	}
	if(a[1]!=0 && a[1]!=-1){printf("0\n");return 0;}
	if(a[n]!=0 && a[n]!=-1){printf("0\n");return 0;}
	dp[1][0]=1;
	for(i=2;i<=n;i++){
        for(j=0;j<=i;j++)dp[i%2][j]=0;
        if(a[i]==-1){
            for(j=0;j<=i;j++){
                if(j>0 && j<i)dp[i%2][j]+=(dp[(i-1)%2][j]%Mod+dp[(i-1)%2][j-1]%Mod+dp[(i-1)%2][j+1]%Mod)%Mod;
                else if(j==i)dp[i%2][j]+=(dp[(i-1)%2][j]%Mod+dp[(i-1)%2][j-1]%Mod)%Mod;
                else if(j==0)dp[i%2][j]+=(dp[(i-1)%2][j]%Mod+dp[(i-1)%2][j+1]%Mod)%Mod;
            }
        }
        else{
            if(a[i]!=0) dp[i%2][a[i]]+=(dp[(i-1)%2][a[i]-1]%Mod+dp[(i-1)%2][a[i]+1]%Mod+dp[(i-1)%2][a[i]]%Mod)%Mod;
            else dp[i%2][a[i]]+=(dp[(i-1)%2][a[i]+1]%Mod+dp[(i-1)%2][a[i]]%Mod)%Mod;
        }
	}
	printf("%lld\n",dp[n%2][0]);
    return 0;
}
/*
6
-1 -1 2 -1 -1 -1
*/
