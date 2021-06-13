/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[110],dp[110][110];
int play(int l,int r){
    if(l==r)return 0;
    if(dp[l][r]!=-1)return dp[l][r];
    int i,Min=1<<30,temp,temp2;
    for(i=l;i<r;i++){
        temp=play(l,i);
        temp2=play(i+1,r);
        Min=min(Min,temp+temp2+((a[r]-a[i])%100)*((a[i]-a[l-1])%100));
    }
    return dp[l][r]=Min;
}
int main()
{
    int q,n,i;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(i=1;i<=n;i++)scanf("%d",&a[i]),a[i]+=a[i-1];
        memset(dp,-1,sizeof dp);
        printf("%d\n",play(1,n));
    }
    return 0;
}
/*

*/
