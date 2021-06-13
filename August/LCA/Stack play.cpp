/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int lv[300010],n,like[300010],dp[23][300010];
int LCA(int a,int b){
    int i;
    if(lv[b]>lv[a])swap(a,b);
    for(i=20;i>=0;i--){
        if(lv[dp[i][a]]>=lv[b])a=dp[i][a];
    }
    if(a==b)return lv[a];
    for(i=20;i>=0;i--){
        if(dp[i][a]!=dp[i][b])a=dp[i][a],b=dp[i][b];
    }
    return lv[a]-1;
}
int main()
{
    int i,a,j,b;
    char opr;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf(" %c",&opr);
        if(opr=='a'){
            scanf("%d",&a);
            dp[0][i]=like[a];
            lv[i]=lv[like[a]]+1;
            like[i]=i;
            for(j=1;j<=20;j++){
                dp[j][i]=dp[j-1][dp[j-1][i]];
            }
        }
        if(opr=='b'){
            scanf("%d",&a);
            like[i]=dp[0][like[a]];
            dp[0][i]=dp[1][like[a]];
            lv[i]=lv[dp[1][like[a]]]+1;
            printf("%d\n",like[a]);
            for(j=1;j<=20;j++){
                dp[j][i]=dp[j-1][dp[j-1][i]];
            }
        }
        if(opr=='c'){
            scanf("%d %d",&a,&b);
            printf("%d\n",LCA(like[a],like[b]));
            like[i]=like[a];
            for(j=0;j<=20;j++){
                dp[j][i]=dp[j][a];
            }
        }
    }
    return 0;
}
/*
10
a 0
a 1
a 2
a 3
a 2
c 4 5
a 5
b 7
b 7
c 9 7
*/
