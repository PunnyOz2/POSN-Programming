/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char a[10010];
char b[10010];
int dp[2][10100];
int main()
{
    int i,j,lena,lenb,ans=-1,att;
    scanf(" %s %s",a+1,b+1);
    lena=strlen(a+1),lenb=strlen(b+1);
    for(i=1;i<=lena;i++){
        for(j=1;j<=lenb;j++){
            if(a[i]!=b[j])dp[i%2][j]=0;
            else{
                dp[i%2][j]=dp[(i-1)%2][j-1]+1;
                if(dp[i%2][j]>ans)
                    ans = dp[i%2][j],att=j;
            }
        }
    }
    for(i=att-ans+1;i<=att;i++)
        printf("%c",b[i]);

    return 0;
}
/*
abcdefabc
bacdefabcde
*/
