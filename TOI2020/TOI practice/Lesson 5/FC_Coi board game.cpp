#include<bits/stdc++.h>
using namespace std;
char a[510][510];
int dis[510][510][9];
int di[]={1,-1,0,0},dj[]={0,0,1,-1};
struct A{
    int i,j,w,mark;
};
queue<A> q;
int main(){
    int n,m,i,j,k,sti,stj,eni,enj,w,mark,ni,nj;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)scanf(" %s",a[i]+1);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(a[i][j]=='S')sti=i,stj=j;
            if(a[i][j]=='E')eni=i,enj=j;
            for(k=0;k<8;k++)dis[i][j][k]=1<<30;
        }
    }
    dis[sti][stj][0]=0;
    q.push({sti,stj,0,0});
    while(!q.empty()){
        i=q.front().i;
        j=q.front().j;
        w=q.front().w;
        mark=q.front().mark;
        if(i==eni && j==enj){printf("%d\n",w);return 0;}
        q.pop();
        for(k=0;k<4;k++){
            ni=i+di[k];
            nj=j+dj[k];
            if(ni<1 || nj<1 || ni>n || nj>m)continue;
            if(a[ni][nj]=='#')continue;
            if(a[ni][nj]=='J' && (mark&4)==4){
                if(dis[ni][nj][mark]>dis[i][j][mark]+1){
                    dis[ni][nj][mark]=dis[i][j][mark]+1;
                    q.push({ni,nj,dis[ni][nj][mark],mark});
                }
            }
            if(a[ni][nj]=='B' && (mark&2)==2){
                if(dis[ni][nj][mark]>dis[i][j][mark]+1){
                    dis[ni][nj][mark]=dis[i][j][mark]+1;
                    q.push({ni,nj,dis[ni][nj][mark],mark});
                }
            }
            if(a[ni][nj]=='P' && (mark&1)==1){
                if(dis[ni][nj][mark]>dis[i][j][mark]+1){
                    dis[ni][nj][mark]=dis[i][j][mark]+1;
                    q.push({ni,nj,dis[ni][nj][mark],mark});
                }
            }
            if(a[ni][nj]=='j'){
                if(dis[ni][nj][mark|4]>dis[i][j][mark]+1){
                    dis[ni][nj][mark|4]=dis[i][j][mark]+1;
                    q.push({ni,nj,dis[ni][nj][mark|4],mark|4});
                }
            }
            if(a[ni][nj]=='b'){
                if(dis[ni][nj][mark|2]>dis[i][j][mark]+1){
                    dis[ni][nj][mark|2]=dis[i][j][mark]+1;
                    q.push({ni,nj,dis[ni][nj][mark|2],mark|2});
                }
            }
            if(a[ni][nj]=='p'){
                if(dis[ni][nj][mark|1]>dis[i][j][mark]+1){
                    dis[ni][nj][mark|1]=dis[i][j][mark]+1;
                    q.push({ni,nj,dis[ni][nj][mark|1],mark|1});
                }
            }
            if(a[ni][nj]=='.' || a[ni][nj]=='E' || a[ni][nj]=='S'){
                if(dis[ni][nj][mark]>dis[i][j][mark]+1){
                    dis[ni][nj][mark]=dis[i][j][mark]+1;
                    q.push({ni,nj,dis[ni][nj][mark],mark});
                }
            }
        }
    }
    printf("-1\n");
    return 0;
}
/*
2 5
S.J.b
.jB.E
*/
