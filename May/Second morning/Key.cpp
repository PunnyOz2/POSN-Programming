/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1200][1200];
char a[1200],b[1200],c[2200];
int main()
{
    int lena,lenb,q,i,j;
    scanf(" %s",a+1);
    scanf(" %s",b+1);
    scanf("%d",&q);
    lena=strlen(a+1);
    lenb=strlen(b+1);
    while(q--){
        memset(dp,0,sizeof dp);
        scanf(" %s",c+1);
        dp[0][0]=1;
        for(i=1;i<=lena;i++){
            if(a[i]!=c[i]){break;}
            dp[i][0]=1;
        }
        for(i=1;i<=lenb;i++){
            if(b[i]!=c[i]){break;}
            dp[0][i]=1;
        }
        for(i=1;i<=lena;i++){
            for(j=1;j<=lenb;j++){
                if(c[i+j]==b[j])dp[i][j]=max(dp[i][j],dp[i][j-1]);
                if(c[i+j]==a[i])dp[i][j]=max(dp[i][j],dp[i-1][j]);
            }
        }
        if(dp[lena][lenb]==1)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
/*
BAB
AB
4
BAABB
BABAB
ABBAB
BBABA
*/
