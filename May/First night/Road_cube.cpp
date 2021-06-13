/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[103][10003];
int dis[103][10003];
int mal[103][10003],mal2[103][10003];
deque<pair<int,int>> Ma;
int main()
{
    int n,m,k,i,j,ans=0,kk;
    scanf("%d %d %d",&n,&m,&k);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
        ans=0;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            while(!Ma.empty() && j-Ma.front().second>k)Ma.pop_front();
            while(!Ma.empty() && Ma.back().first<dis[i-1][j])Ma.pop_back();
            Ma.push_back({dis[i-1][j],j});
            mal[i-1][j]=Ma.front().first;
        }
        Ma.clear();
        for(j=m;j>0;j--){
            while(!Ma.empty() && Ma.front().second-j>k)Ma.pop_front();
            while(!Ma.empty() && Ma.back().first<dis[i-1][j])Ma.pop_back();
            Ma.push_back({dis[i-1][j],j});
            mal2[i-1][j]=Ma.front().first;
        }
        Ma.clear();
        for(int j=1;j<=m;j++)   dis[i][j]=a[i][j]+max(mal[i-1][j],mal2[i-1][j]),ans=max(ans,dis[i][j]);
    }
    printf("%d\n",ans);
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

2 10 3
1 2 3 4 5 6 7 8 9 10
1 9 2 8 3 7 4 6 5 5

3 2 0
99 98
30 40
60 52
*/
