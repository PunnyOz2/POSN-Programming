#include <bits/stdc++.h>
using namespace std;
int dis[160][160][3],a[160][160];
int di[4]={1,-1,0,0},dj[4]={0,0,1,-1};
struct A{
    int x,y,mark;
};
queue<A> q;
int main(){
    int n,m,i,j,x,y,cou=0,x0,y0,x1,y1,mark,ni,nj,Min=1<<30;
    scanf("%d %d",&n,&m);
    scanf("%d %d %d %d",&x0,&y0,&x1,&y1);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            dis[i][j][0]=dis[i][j][1]=1<<30;
        }
    }
    q.push({x0,y0,0});
    dis[x0][y0][0]=1;
    while(!q.empty()){
        x=q.front().x;
        y=q.front().y;
        q.pop();
        for(i=0;i<4;i++){
            ni=x+di[i];
            nj=y+dj[i];
            if(dis[x][y][0]+1<dis[ni][nj][0] && a[ni][nj]==1){
                dis[ni][nj][0]=dis[x][y][0]+1;
                q.push({ni,nj,0});
            }
            if(dis[x][y][0]+1<dis[ni][nj][0] && a[ni][nj]==0){
                dis[ni][nj][0]=dis[x][y][0]+1;
            }
        }
    }
    while(!q.empty())q.pop();
    q.push({x1,y1,1});
    dis[x1][y1][1]=1;
    while(!q.empty()){
        x=q.front().x;
        y=q.front().y;
        q.pop();
        for(i=0;i<4;i++){
            ni=x+di[i];
            nj=y+dj[i];
            if(dis[x][y][1]+1<dis[ni][nj][1] && a[ni][nj]==1){
                dis[ni][nj][1]=dis[x][y][1]+1;
                q.push({ni,nj,1});
            }
            if(a[ni][nj]==0 && dis[ni][nj][0]!=1<<30 && dis[x][y][1]+1<dis[ni][nj][1]){
                cou++,Min=min(Min,dis[x][y][1]+dis[ni][nj][0]);
                dis[ni][nj][1]=dis[x][y][1]+1;
            }
        }
    }
    printf("%d\n%d\n",cou,Min);
}
/*
5 8
4 5
2 8
0 0 1 1 0 0 0 0
1 0 1 1 0 1 1 1
1 0 1 1 1 0 0 1
1 1 0 0 1 0 0 1
0 0 1 1 0 1 1 1
*/
