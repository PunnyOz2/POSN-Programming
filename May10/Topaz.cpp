/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char a[60],b[60],c[60],d[60];
long long place[4][60],num[25],dp[60][60][60][60],ca[60][60][60][60];
int main()
{
    long long q,lena,lenb,lenc,lend,i,j,k,l;
    scanf("%lld",&q);
    while(q--){
        scanf(" %s",a+1);
        scanf(" %s",b+1);
        scanf(" %s",c+1);
        scanf(" %s",d+1);
        lena=strlen(a+1);
        lenb=strlen(b+1);
        lenc=strlen(c+1);
        lend=strlen(d+1);
        for(i=0;i<26;i++)num[i]=0;
        for(i=1;i<=lena;i++){
            place[0][i]=num[a[i]-'a'];
            num[a[i]-'a']=i;
        }
        for(i=0;i<26;i++)num[i]=0;
        for(i=1;i<=lenb;i++){
            place[1][i]=num[b[i]-'a'];
            num[b[i]-'a']=i;
        }
        for(i=0;i<26;i++)num[i]=0;
        for(i=1;i<=lenc;i++){
            place[2][i]=num[c[i]-'a'];
            num[c[i]-'a']=i;
        }
        for(i=0;i<26;i++)num[i]=0;
        for(i=1;i<=lend;i++){
            place[3][i]=num[d[i]-'a'];
            num[d[i]-'a']=i;
        }
        for(i=1;i<=lena;i++){
            for(j=1;j<=lenb;j++){
                for(k=1;k<=lenc;k++){
                    for(l=1;l<=lend;l++){
                        if(a[i]==b[j] && b[j]==c[k] && c[k]==d[l]){
                            dp[i][j][k][l]=2*dp[i-1][j-1][k-1][l-1]+1-ca[place[0][i]][place[1][j]][place[2][k]][place[3][l]];
                            ca[i][j][k][l]= ca[place[0][i]][place[1][j]][place[2][k]][place[3][l]]+(dp[i][j][k][l]-dp[i-1][j-1][k-1][l-1]);
                        }
                        else{
                            dp[i][j][k][l]= dp[i][j-1][k-1][l-1]+dp[i-1][j][k-1][l-1]+dp[i-1][j-1][k][l-1]+dp[i-1][j-1][k-1][l]
                                -dp[i][j][k-1][l-1]-dp[i][j-1][k][l-1]-dp[i][j-1][k-1][l]-dp[i-1][j][k][l-1]-dp[i-1][j][k-1][l]-dp[i-1][j-1][k][l]
                                +dp[i][j][k][l-1]
                                +dp[i][j][k-1][l]+dp[i][j-1][k][l]
                                +dp[i-1][j][k][l]-dp[i-1][j-1][k-1][l-1];
                        }
                    }
                }
            }
        }
        printf("%lld\n", dp[lena][lenb][lenc][lend] );
    }
    return 0;
}
