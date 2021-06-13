#include <bits/stdc++.h>
using namespace std;
char a[1020],b[1020],c[2020];
int dp[1020][1020];
int main(){
    int lena,lenb,i,j,q;
    scanf(" %s",a+1);
    scanf(" %s",b+1);
    lena=strlen(a+1);
    lenb=strlen(b+1);
    scanf("%d",&q);
    while(q--){
        scanf(" %s",c+1);
        for(i=1;i<=lena;i++){
            if(c[i]==a[i])dp[0][i]=dp[0][i-1]+1;
            else dp[0][i]=dp[0][i-1];
        }
        for(i=1;i<=lenb;i++){
            if(c[i]==b[i])dp[i][0]=dp[i-1][0]+1;
            else dp[i][0]=dp[i-1][0];
        }
        for(i=1;i<=lenb;i++){
            for(j=1;j<=lena;j++){
                dp[i][j]=0;
                if(c[i+j]==a[j])dp[i][j]=max(dp[i][j],dp[i][j-1]+1);
                if(c[i+j]==b[i])dp[i][j]=max(dp[i][j],dp[i-1][j]+1);
            }
        }
//        for(i=1;i<=lenb;i++){
//            for(j=1;j<=lena;j++){
//                printf("%d ",dp[i][j]);
//            }
//            printf("\n");
//        }
        if(dp[lenb][lena]==lenb+lena)printf("Yes\n");
        else printf("No\n");
    }
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
