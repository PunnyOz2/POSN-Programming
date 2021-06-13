/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[300];
int dp[300][300][3];
int mark[300][300];
void play(int l,int r){
    if(mark[l][r]==1)return ;
    if(l==r)dp[l][r][a[l]]=1;
    int i;
    //printf("%d %d\n",l,r);
    for(i=l;i<r;i++){
        play(l,i);
        play(i+1,r);
        if(dp[l][i][0]==1 && dp[i+1][r][0]==1)dp[l][r][2]=1;
        if(dp[l][i][0]==1 && dp[i+1][r][1]==1)dp[l][r][1]=1;
        if(dp[l][i][0]==1 && dp[i+1][r][2]==1)dp[l][r][0]=1;
        if(dp[l][i][1]==1 && dp[i+1][r][0]==1)dp[l][r][2]=1;
        if(dp[l][i][1]==1 && dp[i+1][r][1]==1)dp[l][r][1]=1;
        if(dp[l][i][1]==1 && dp[i+1][r][2]==1)dp[l][r][1]=1;
        if(dp[l][i][2]==1 && dp[i+1][r][0]==1)dp[l][r][1]=1;
        if(dp[l][i][2]==1 && dp[i+1][r][1]==1)dp[l][r][2]=1;
        if(dp[l][i][2]==1 && dp[i+1][r][2]==1)dp[l][r][1]=1;
    }
    mark[l][r]=1;
    return ;
}
int main()
{
    int q=20,n,i;
    char num;
    while(q--){
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf(" %c",&num);
            a[i]=num-'0';
        }
        play(1,n);
        if(dp[1][n][0]==1)printf("yes\n");
        else printf("no\n");
        memset(mark,0,sizeof mark);
        memset(dp,0,sizeof dp);
    }
    return 0;
}
/*
4 0201
5 10212
6 002000
5 01010
5 02112
5 11020
5 10112
5 02000
5 12122
5 12201
5 02200
5 01200
5 10102
5 10210
5 12110
5 12112
5 20122
5 01022
2 00
2 02
*/
