/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char a[1010],b[1010];
int dp[1010][1010];
int main()
{
    int q,lena,lenb,i,j;
    scanf("%d ",&q);
    while(q--){
        scanf(" %s %s",a+1,b+1);
        lena=strlen(a+1);
        lenb=strlen(b+1);
        for(i=1;i<=lena;i++){
            dp[i][0]=i;
        }
        for(i=1;i<=lenb;i++){
            dp[0][i]=i;
        }
        for(i=1;i<=lena;i++){
            for(j=1;j<=lenb;j++){
                if(a[i]==b[j])
                    dp[i][j]=dp[i-1][j-1];
                else
                    dp[i][j]=min(dp[i][j-1],min(dp[i-1][j-1],dp[i-1][j]))+1;
            }
        }
        printf("%d\n",dp[lena][lenb]);
        memset(dp,0,sizeof dp);
    }
    return 0;
}
