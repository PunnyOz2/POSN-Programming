/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char a[1010];
int dp[1010][1010];
int main()
{
    int lena,i,j,ii,Max=1,pos;
    scanf(" %s",a);
    lena=strlen(a);
    for(i=0;i<lena;i++){
        dp[i][i]=1;
    }
    for(i=lena-2;i>=0;i--){
        if(a[i]==a[i+1]){dp[i][i+1]=1;Max=2;pos=i;}
    }
    for(i=3;i<=lena;i++){
        for(j=lena-i;j>=0;j--){
            ii=i+j-1;
            if(a[j]==a[ii]&& dp[j+1][ii-1]==1)dp[j][ii]=1,Max=i,pos=j;
        }
    }
    for(i=pos;i<pos+Max;i++){
        printf("%c",a[i]);
    }
    return 0;
}
