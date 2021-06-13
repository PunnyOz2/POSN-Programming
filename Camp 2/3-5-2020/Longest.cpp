/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[1100][1100];
int dp[4][1100][1100];
priority_queue<int> q;
int main()
{
    int n,m,Q,i,j,ans,temp,cou,k,ii,jj;
    scanf("%d",&Q);
    while(Q--){
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                scanf("%d",&a[i][j]);
            }
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                if(a[i][j]>=a[i][j-1] && j-1!=0)dp[0][i][j]=dp[0][i][j-1]+1;
            }
            for(j=m;j>=1;j--){
                if(a[i][j]>=a[i][j+1] && j!=m)dp[1][i][j]=dp[1][i][j+1]+1;
            }
        }
        for(j=1;j<=m;j++){
            for(i=1;i<=n;i++){
                if(a[i][j]>=a[i-1][j] && i-1!=0)dp[2][i][j]=dp[2][i-1][j]+1;
            }
            for(i=n;i>=1;i--){
                if(a[i][j]>=a[i+1][j] && i!=n)dp[3][i][j]=dp[3][i+1][j]+1;
            }
        }
        ans=0;
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                temp=0,cou=0;
                for(k=0;k<4;k++){
                    temp+=dp[k][i][j];
                }
                temp++;
                if(temp>ans)ans=temp,ii=i,jj=j;
                while(!q.empty())q.pop();
            }
        }
        printf("%d\n%d %d\n",ans,ii,jj);
        memset(dp,0,sizeof dp);
    }
    return 0;
}
/*
2
4 6
7 3 5 7 2 4
1 5 2 6 2 10
8 4 1 2 3 2
10 7 10 7 3 8
4 4
5 4 1 2
4 2 2 3
4 4 3 5
1 2 2 6
*/
