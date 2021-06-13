#include<bits/stdc++.h>
using namespace std;
int dp[110][10100];
deque<int> ma;
int main(){
    int n,m,k,i,j,l,r;
    scanf("%d %d %d",&n,&m,&k);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%d",&dp[i][j]);
        }
    }
    for(i=n-1;i>=1;i--){
        for(j=1;j<=1+k-1;j++){
            while(!ma.empty() && dp[i+1][ma.back()]<=dp[i+1][j])ma.pop_back();
            ma.push_back(j);
        }
        r=1+k-1;
        for(j=1;j<=m;j++){
            l=max(1,j-k);
            while(r<j+k && r<m){
                r++;
                while(!ma.empty() && dp[i+1][ma.back()]<=dp[i+1][r])ma.pop_back();
                ma.push_back(r);
            }
            //printf("%d %d %d %d\n",i,j,l,ma.front());
            while(!ma.empty() && ma.front()<l)ma.pop_front();
            dp[i][j]+=dp[i+1][ma.front()];
        }
        while(!ma.empty())ma.pop_back();
    }
//    for(i=1;i<=n;i++){
//        for(j=1;j<=m;j++)printf("%d ",dp[i][j]);
//        printf("\n");
//    }
    int Max=0;
    for(i=1;i<=m;i++)Max=max(Max,dp[1][i]);
    printf("%d\n",Max);
    return 0;
}
/*
8 5 2
0 0 5 4 0
2 0 7 0 0
0 8 0 3 0
9 0 0 0 0
0 0 1 9 0
0 0 0 0 9
0 0 0 0 9
9 0 1 0 0
*/
