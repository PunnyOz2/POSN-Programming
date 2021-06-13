/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char a[500003];
char b[610];
int dp[500002][601];
int main()
{
    int n,q,lena,i,j,lenb,now,cou,Max;
    scanf("%d %d",&n,&q);
    scanf(" %s",a+1);
    lena=strlen(a+1);
    while(q--){
        scanf(" %s",b+1);
        lenb=strlen(b+1);
        for(i=1;i<=lena;i++){
            for(j=1;j<=lenb;j++){
                if(a[i]==b[j])dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
        printf("%d\n",dp[lena][lenb]);
        //memset(dp,0,sizeof dp);
    }
    return 0;
}
/*
5 2
ABCDE
CD
BBABBC
*/
