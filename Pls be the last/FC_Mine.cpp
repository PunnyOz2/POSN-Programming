/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010][1010][4],qs[1010][1010][4];
int dp[1010][1010][4],dp2[1010][1010][4];
deque<int>Ma;
int main()
{
    int n,kk,k,j,i;
    scanf("%d %d",&n,&kk);
    for(k=0;k<3;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                scanf("%d",&a[i][j][k]);
                a[i][j][k]+=a[i-1][j][k]+a[i][j-1][k]-a[i-1][j-1][k];
                if(i>=kk && j>=kk)qs[i][j][k]=a[i][j][k]-a[i-kk][j][k]-a[i][j-kk][k]+a[i-kk][j-kk][k];
            }
        }
    }
    for(k=0;k<3;k++){
        for(i=kk;i<=n;i++){
            for(j=n;j>=kk;j--){
                while(!Ma.empty() && Ma.front()>=j+kk)Ma.pop_front();
                while(!Ma.empty() && qs[i][Ma.back()][k]<qs[i][j][k])Ma.pop_back();
                Ma.push_back(j);
                dp[i][j][k]=qs[i][Ma.front()][k];
            }
            while(!Ma.empty())Ma.pop_back();
        }
        for(j=kk;j<=n;j++){
            for(i=n;i>=kk;i--){
                while(!Ma.empty() && Ma.front()>=i+kk)Ma.pop_front();
                while(!Ma.empty() && dp[Ma.back()][j][k]<dp[i][j][k])Ma.pop_back();
                Ma.push_back(i);
                dp2[i][j][k]=dp[Ma.front()][j][k];
            }
            while(!Ma.empty())Ma.pop_back();
        }
    }
    int Max=-1<<30;
    for(i=kk;i<=n;i++){
        for(j=kk;j<=n;j++){
            //printf("%d ",dp2[i][j][0]);
            Max=max(Max,dp2[i][j][0]+dp2[i][j][1]+dp2[i][j][2]);
        }
        printf("\n");
    }
    printf("%d\n",Max);
    return 0;
}
/*
3 2
1 2 3 4 5 6 7 8 9
1 2 3 4 5 6 7 8 9
9 8 7 6 5 4 3 2 1

4 2
7 7 1 1
7 7 1 1
1 1 1 1
1 1 1 1
1 8 8 1
1 8 8 1
1 1 1 1
1 1 1 1
1 1 1 1
9 9 1 1
9 9 1 1
1 1 1 1
*/
