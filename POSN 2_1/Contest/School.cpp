/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int di[4]={1,-1,0,0},dj[4]={0,0,1,-1};
int i,j,a[100][100],dp[100][100],Max=0,ii,jj,iii,jjj,cou,k,mark[100][100],Min;
struct A{
    int i,j;
};
stack<A> st;
queue<A> q;
int main()
{
	int n,m;
	scanf("%d %d",&m,&n);
	for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf(" %c",&a[i][j]);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(a[i][j]=='T')dp[i][j]=0;
            else{
                dp[i][j]=min(dp[i][j-1]+1,min(dp[i-1][j]+1,dp[i-1][j-1]+1));
                if(dp[i][j]==Max)st.push({i,j});
                if(dp[i][j]>Max){
                    while(!st.empty())st.pop();
                    Max=dp[i][j];
                    st.push({i,j});
                }
            }
        }
    }
    Min=1<<30;
    while(!st.empty()){
        ii=st.top().i,jj=st.top().j,st.pop();
        cou=0;
        for(i=ii-Max+1;i<=ii;i++){
            for(j=jj-Max+1;j<=jj;j++){
                if(a[i][j]=='P' && mark[i][j]!=1)cou++,mark[i][j]=1,q.push({i,j});
                while(!q.empty()){
                    iii=q.front().i,jjj=q.front().j,q.pop();
                    for(k=0;k<4;k++){
                        if(a[iii+di[k]][jjj+dj[k]]=='P' && mark[iii+di[k]][jjj+dj[k]]!=1)mark[iii+di[k]][jjj+dj[k]]=1,q.push({iii+di[k],jjj+dj[k]});
                    }
                }
            }
        }
        Min=min(cou,Min);
        memset(mark,0,sizeof mark);
    }
    printf("%d %d",Max*Max,Min);
    return 0;
}
/*
8 6
SSSSSSSS
SSSSSSSS
SPPSSSSS
SSSPSSSS
SSSSSTTS
PSSSSTSS
*/
