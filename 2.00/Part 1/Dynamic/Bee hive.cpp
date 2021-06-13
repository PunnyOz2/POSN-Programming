/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1100][1100];
struct A{
    int i,j,w;
};
stack<A> st;
int main()
{
    int n,m,i,j,cou=0,Max=-1000000,w,jj;
    scanf("%d %d",&n,&m);
    for(i=n;i>=1;i--){
        for(j=1;j<=m;j++){
            scanf("%d",&dp[i][j]);
        }
    }
    cou=0;
    for(jj=1;jj<=m;jj++){
        st.push({1,jj,0});
    while(!st.empty()){
        i=st.top().i,j=st.top().j,w=st.top().w,st.pop();
        w+=dp[i][j];
        if(i==n && w>Max){
            cou=1,Max=max(w,Max);
        }
        else if(i==n&&w==Max)cou++;
        else if(i==n&&w<Max)continue;
        else if(i%2==1){
            if(dp[i+1][j-1]>dp[i+1][j])
                st.push({i+1,j-1,w});
            else if(dp[i+1][j-1]<dp[i+1][j])
                st.push({i+1,j,w});
            else{
                st.push({i+1,j,w});
                if(j-1>=1)st.push({i+1,j-1,w});
            }
        }
        else if(i%2==0){
            if(dp[i+1][j+1]>dp[i+1][j])
                st.push({i+1,j+1,w});
            else if(dp[i+1][j+1]<dp[i+1][j])
                st.push({i+1,j,w});
            else{
                st.push({i+1,j,w});
                if(j+1<=m)st.push({i+1,j+1,w});
            }
        }
    }
    }
    printf("%d %d",Max,cou);
    return 0;
}
/*
7 5
10 8 24 13 16
4 23 12 1 14
14 17 18 11 26
6 3 3 8 10
4 5 16 5 14
8 4 4 1 7
8 3 1 4 5

5 5
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
2 1 2 1 2
1 2 1 2 1
*/
