/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[100100],b[100100],dp[2][100100];
int main()
{
    int n;
    scanf("%d",&n);
    for(i=n;i>0;i--){
        scanf("%d",&a[i]);
    }
    a[0]=0;
    for(i=n;i>0;i--){
        scanf("%d",&b[i]);
    }
    b[0]=1;
    for(i=n;i>0;i--){
        for(j=1;j<=a[i];j++)dp[i%2][j]++;
        for(j=a[i-1];j<=a[i];j++)dp[(i+1)%2][a[i-1]]+=dp[i%2][j],ans+=((j-a[i-1])*b[i-1]);
        for(j=1;j<a[i-1];j++)dp[(i+1)%2][j]+=dp[i%2][j];
    }
    return 0;
}
