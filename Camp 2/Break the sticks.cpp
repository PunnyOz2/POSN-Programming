/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010],dp[1010][1010];
int play(int l,int r,int ll,int rr){
    if(l+1==r)return 0;
    if(dp[l][r]!=0)return dp[l][r];
    int temp,temp2,Min=1<<30,i;
    for(i=l+1;i<r;i++){
        temp=play(l,i,ll,a[i]);
        temp2=play(i,r,a[i],rr);
        Min=min(Min,rr-ll+temp+temp2);
    }
    return dp[l][r]=Min;
}
int main()
{
    int n,m,i;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
        scanf("%d",&a[i]);
    printf("%d",play(0,m+1,0,n));
    return 0;
}
/*
100 3
25 50 75
*/
