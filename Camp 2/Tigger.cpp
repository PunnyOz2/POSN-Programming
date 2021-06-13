/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1010][1010],n,i,a[1010];
int play(int i,int pow){
    if(i>n || i<1)return 1<<30;
    if(dp[i][pow]!=0)return dp[i][pow];
    if(i==n)return a[n];
    return dp[i][pow]=a[i]+min(play(i+pow+1,pow+1),play(i-pow,pow));
}
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    printf("%d\n",play(2,1));
    return 0;
}
/*

*/
