/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char a[1200];
int dp[1200][1200];
int ans[1200];
int main()
{
    int lena,i,j,ii;
    for( i=1;i<=10;i++){
        scanf(" %s",a+1);
        lena=strlen(a+1);
        memset(dp,0,sizeof dp);
        ii=1;
        while(a[ii]){
            a[ii]=tolower(a[ii]);
            ii++;
        }
        for(ii=1;ii<=lena;ii++){
            for( j=1;j<=lena;j++){
                if(a[ii]==a[lena-j+1])dp[ii][j]=dp[ii-1][j-1]+1;
                else dp[ii][j]=max(dp[ii-1][j],dp[ii][j-1]);
            }
        }
        ans[i]=dp[lena][lena]%10;
    }
    for(i=1;i<=10;i++)printf("%d",ans[i]);
    return 0;
}

