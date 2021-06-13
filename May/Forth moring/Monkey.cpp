/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[6000],dp[6000];
int main()
{
    int n,m,i,j,k;
    for(i=1;i<=5600;i++)dp[i]=1<<30;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(i=1;i<=n;i++){
        m=0;
        for(j=i;j>=1 && j>=i-k+1;j--){
            m=max(m,a[j]);
            dp[i]=min(dp[i],m+dp[j-1]);
        }
    }
    printf("%d\n",dp[n]);
    return 0;
}
/*
8 5
1
4
0
3
2
7
2
2
*/
