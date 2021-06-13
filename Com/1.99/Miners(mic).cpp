/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dp[100100][4][4][4][4],a[100100];
char str[100100];
int dif(int i,int j,int k){
    int cnt=0;
    if(i==1||j==1||k==1) cnt++;
    if(i==2||j==2||k==2) cnt++;
    if(i==3||j==3||k==3) cnt++;
    return cnt;
}
int main()
{
    int n,i,j,k,l,m,ans=-1;
	scanf("%d %s",&n,str+1);
	for(i=1;i<=n;i++){
        if(str[i]=='M') a[i]=1;
        if(str[i]=='F') a[i]=2;
        if(str[i]=='B') a[i]=3;
	}
	for(i=0;i<=n;i++)
        for(j=0;j<4;j++)
            for(k=0;k<4;k++)
                for(l=0;l<4;l++)
                    for(m=0;m<4;m++)
                    dp[i][j][k][l][m]=-1<<30;
        dp[1][0][a[1]][0][0]=dp[1][0][0][0][a[1]]=1;
        for(i=2;i<=n;i++){
            for(j=0;j<4;j++)
                for(k=0;k<4;k++)
                for(l=0;l<4;l++){
                    for(m=0;m<4;m++){
                        dp[i][k][a[i]][l][m]=max(dp[i][k][a[i]][l][m],dp[i-1][j][k][l][m]+dif(a[i],j,k));
                        dp[i][j][k][m][a[i]]=max(dp[i][j][k][m][a[i]],dp[i-1][j][k][l][m]+dif(a[i],l,m));
                    }

                }
        }
        for(j=0;j<4;j++)
            for(k=0;k<4;k++)
                for(l=0;l<4;l++)
                    for(m=0;m<4;m++)
                        ans=max(ans,dp[n][j][k][l][m]);
        printf("%d\n",ans);
    return 0;
}
