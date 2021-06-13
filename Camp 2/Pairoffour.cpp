/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1010][1010];
char a[1010];
int play(int l,int r){
    if(l>=r)return 0;
    if(dp[l][r]!=-1)return dp[l][r];
    int cou=0;
    if(a[l]==a[r]){
        cou+=play(l+1,r-1);
        cou++;
        return dp[l][r]=cou;
    }
    int temp,temp2,Max=-1<<30,i;
    for(i=l;i<r;i++){
        temp=play(l,i);
        temp2=play(i+1,r);
        Max=max(Max,temp+temp2);
    }
    return dp[l][r]=Max;
}
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf(" %c",&a[i]);
    }
    memset(dp,-1,sizeof dp);
    printf("%d\n",play(1,n));
    return 0;
}
/*
12
U B O U B O U B O U B O

6
U U B N B O

U B O N O B U
*/
