#include <bits/stdc++.h>
using namespace std;
int a[70][70],mark[70][70],idx[70][70],dp[70][70],mmark[4900];
int di[4]={1,-1,0,0},dj[4]={0,0,1,-1};
char b[70];
struct A{
    int x,y;
};
queue<A> q;
int main(){
    int n,m,i,j,Max=0,x,y,k,ni,nj;
    scanf("%d %d",&m,&n);
    for(i=1;i<=n;i++){
        scanf(" %s",b+1);
        for(j=1;j<=m;j++){
            if(b[j]=='S'){
                a[i][j]=1;
            }
            else if(b[j]=='P'){
                a[i][j]=1;
                mark[i][j]=1;
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(a[i][j]==0)continue;
            dp[i][j]=min(dp[i][j-1],dp[i-1][j]);
            dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
            dp[i][j]++;
            Max=max(Max,dp[i][j]);
        }
    }
//    for(i=1;i<=n;i++){
//        for(j=1;j<=m;j++){
//            printf("%d ",dp[i][j]);
//        }
//        printf("\n");
//    }
    int id=1;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(mark[i][j]==1 && idx[i][j]==0){
                q.push({i,j});
                idx[i][j]=id;
                while(!q.empty()){
                    x=q.front().x;
                    y=q.front().y;
                    q.pop();
                    for(k=0;k<4;k++){
                        ni=x+di[k];
                        nj=y+dj[k];
                        if(mark[ni][nj]==1 && idx[ni][nj]==0){
                            q.push({ni,nj});
                            idx[ni][nj]=id;
                        }
                    }
                }
                id++;
            }
        }
    }
    int cou,ii,jj,Mina=1<<30;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(dp[i][j]==Max){
                cou=0;
                for(ii=i-Max+1;ii<=i;ii++){
                    for(jj=j-Max+1;jj<=j;jj++){
                        if(idx[ii][jj]!=0 && mmark[idx[ii][jj]]==0){
                            mmark[idx[ii][jj]]=1;
                            cou++;
                        }
                    }
                }
                Mina=min(Mina,cou);
                memset(mmark,0,sizeof mmark);
            }
        }
    }
    if(Mina==1<<30)Mina=0;
    printf("%d %d\n",Max*Max,Mina);
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
