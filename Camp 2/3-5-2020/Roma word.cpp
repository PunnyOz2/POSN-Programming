/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char a[10100],b[10100],c[1100];
int dp[2][10100];
int pos[2100][2100];
int main()
{
    int lena,lenb,Max,i,j,idx;
    scanf(" %s",a+1);
    scanf(" %s",b+1);
    lena=strlen(a+1);
    lenb=strlen(b+1);
    for(i=1;i<=lena;i++){
        for(j=1;j<=lenb;j++){
            if(a[i]==b[j]){
                dp[i%2][j]=dp[(i+1)%2][j-1]+1;
                pos[i][j]=1;
            }
            else{
                if(dp[i%2][j-1]>dp[(i+1)%2][j]){
                    dp[i%2][j]=dp[i%2][j-1];
                    pos[i][j]=2;
                }
                else{
                    dp[i%2][j]=dp[(i+1)%2][j];
                    pos[i][j]=3;
                }
            }
        }
    }
    int cou=0;
    i=lena,j=lenb;
    while(i>0 && j>0){
        if(pos[i][j]==1){
            c[cou++]=a[i];
            i--,j--;
        }
        else if(pos[i][j]==2)j--;
        else i--;
    }
    printf("%d\n",cou);
    if(!cou)printf("No Roma word\n");
    else for(i=cou-1;i>=0;i--)printf("%c",c[i]);
    return 0;
}
