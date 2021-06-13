/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[100],dp[100][100];
int main()
{
    int l,p,i,j,k;
    scanf("%d %d",&l,&p);
    for(i=1;i<=p;i++)scanf("%d",&a[i]);
    a[p+1]=l;
    for(i=0;i<=p+1;i++){
        for(j=0;j<=p+1;j++){
                if(j-i>1)dp[i][j]=1e9;
        }
    }
    for(k=1;k<=p+1;k++){
        for(i=0;i<=p+1-k;i++){
            for(j=i+1;j<i+k;j++){
                dp[i][i+k]=min(dp[i][j]+dp[j][i+k]+a[i+k]-a[i],dp[i][i+k]);
            }
        }
    }
    printf("%d",dp[0][p+1]);
    return 0;
}
/*
100 3
25 50 75
*/
