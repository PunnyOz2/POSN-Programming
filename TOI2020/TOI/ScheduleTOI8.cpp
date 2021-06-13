#include <bits/stdc++.h>
using namespace std;
struct A{
    int i,j;
};
int a[1010],b[1010];
A dp[1010][1010];
int main(){
    int t,n,i,j;
    scanf("%d %d",&t,&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(i=1;i<=n;i++){
        scanf("%d",&b[i]);
    }
    for(i=1;i<=n;i++){
        dp[0][i]=dp[0][i-1];
        if(dp[0][i].j+a[i]<=t) dp[0][i].j+=a[i];
        else dp[0][i].i++, dp[0][i].j=a[i];
    }
    for(i=1;i<=n;i++){
        dp[i][0]=dp[i-1][0];
        if(dp[i-1][0].j+b[i]<=t) dp[i][0].j+=b[i];
        else dp[i][0].i++, dp[i][0].j=b[i];
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            A x,y,now,now2;
            x=dp[i-1][j];
            y=dp[i][j-1];
            if(x.j+b[i]<=t) now.j=x.j+b[i], now.i=x.i;
            else now.j=b[i], now.i=x.i+1;
            if(y.j+a[j]<=t) now2.j=y.j+a[j], now2.i=y.i;
            else now2.j=a[j], now2.i=y.i+1;
            if(now.i>now2.i || (now.i==now2.i && now.j>=now2.j))dp[i][j]=now2;
            else dp[i][j]=now;
        }
    }
//    for(i=1;i<=n;i++){
//        for(j=1;j<=n;j++){
//            printf("%d.%d ",dp[i][j].i,dp[i][j].j);
//        }
//        printf("\n");
//    }
    printf("%d\n%d\n",dp[n][n].i+1,dp[n][n].j);
}
/*
8
4
4 5 6 4
3 3 2 4
*/
