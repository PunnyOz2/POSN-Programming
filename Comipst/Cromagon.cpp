/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dp[25][120][120],mark[120][120];
int n,m,k,i,a,b,c;
int ch[120][120];
int ar[500];
void play(int l,int r){
    int Max=-1,i,j,h;
    if(l==r){
        dp[ar[l]][l][r]=1;return;
    }
    for(i=l;i<r;i++){
        if(mark[l][i]==0)play(l,i),mark[l][i]=1;
        if(mark[i+1][r]==0)play(i+1,r),mark[i+1][r]=1;
        for(j=0;j<k;j++){
            for(h=0;h<k;h++){
                if(dp[j][l][i]>=1 && dp[h][i+1][r]>=1)dp[ch[j][h]][l][r]+=dp[j][l][i]*dp[h][i+1][r],dp[ch[j][h]][l][r]%=2009;
            }
        }
    }
}
int main()
{
    int j;
    scanf("%d",&k);
    for(i=0;i<k;i++){
        for(j=0;j<k;j++){
            scanf("%d",&ch[i][j]);
        }
    }
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&ar[i]);
    }
    play(1,n);
    for(i=0;i<k;i++){
        printf("%d\n",dp[i][1][n]);
    }
    return 0;
}
