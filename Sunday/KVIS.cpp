/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1003][1003];
int a[1003];
int qs[3][1003];
int main()
{
    int n,m,i,j,l;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]==1)qs[0][i]=1;
        else qs[1][i]=1;
        qs[0][i]+=qs[0][i-1];
        qs[1][i]+=qs[1][i-1];
    }
    for(i=1;i<=m;i++){
        for(j=i;j<=n;j++){
            if(i==1){dp[i][j]=qs[0][j]*qs[1][j];continue;}
            dp[i][j]=1<<30;
            for(l=j-1;l>=i-1;l--){
                dp[i][j]=min((qs[0][j]-qs[0][l])*(qs[1][j]-qs[1][l])+dp[i-1][l],dp[i][j]);
            }
        }
    }
    printf("%d\n",dp[m][n]);
    return 0;
}
