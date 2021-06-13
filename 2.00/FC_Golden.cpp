#include <bits/stdc++.h>
using namespace std;
int a[5500],dp[5500][5500],n1;
int play(int n,int k){
    if(n>n1||k==0) return 0;
    if(dp[n][k]!=0) return dp[n][k];
    if(k==1) return a[n];
    int ans=0,i;
    for(i=0;i<k;i++)
        ans=max(ans,play(n*2,i)+play(n*2+1,k-i-1)+a[n]);
    return dp[n][k]=ans;
}
int main(){
    int k,i,ans=0;
    scanf("%d %d",&n1,&k);
    for(i=1;i<=n1;i++){
        scanf("%d",&a[i]);
    }
    for(i=1;i<=n1;i++)
        ans=max(ans,play(i,k));
    printf("%d",ans);
}
/*
10 5
3 7 1 9 6 2 6 5 4 1
*/
