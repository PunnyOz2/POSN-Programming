/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dp[100100][4][4][4][4];
int play(int i,int j,int k){
    int cou=0;
    if(i==1 || j==1 || k==1)cou++;
    if(i==2 || j==2 || k==2)cou++;
    if(i==3 || j==3 || k==3)cou++;
    return cou;
}
char a[100100];
int ar[100100];
int main()
{
    int n,i,j,k,l,m,Max;
    scanf("%d",&n);
    scanf(" %s",a+1);
    for(i=1;i<=n;i++){
        if(a[i]=='M')ar[i]=1;
        if(a[i]=='F')ar[i]=2;
        if(a[i]=='B')ar[i]=3;
    }
    for(i=0;i<=n;i++){
        for(j=0;j<4;j++){
            for(k=0;k<4;k++){
                for(l=0;l<4;l++){
                    for(m=0;m<4;m++){
                        dp[i][j][k][l][m]=-1<<30;
                    }
                }
            }
        }
    }
    dp[0][0][0][0][0]=0;

    for(i=1;i<=n;i++){
        for(j=0;j<4;j++){
            for(k=0;k<4;k++){
                for(l=0;l<4;l++){
                    for(m=0;m<4;m++){
                        dp[i][j][k][m][ar[i]]=max(dp[i][j][k][m][ar[i]],dp[i-1][j][k][l][m]+play(l,m,ar[i]));
                        dp[i][k][ar[i]][l][m]=max(dp[i][k][ar[i]][l][m],dp[i-1][j][k][l][m]+play(j,k,ar[i]));
                    }
                }
            }
        }
    }
    Max=0;
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            for(k=0;k<4;k++)
                for(l=0;l<4;l++)
                    Max=max(Max,dp[n][i][j][k][l]);
    printf("%d\n",Max);
    return 0;
}
/*
6
MBMFFB
*/
