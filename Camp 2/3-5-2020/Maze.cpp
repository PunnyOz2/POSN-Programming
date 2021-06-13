/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j;
};
queue<A> q;
int a[160][160];
int di[4]={1,-1,0,0},dj[4]={0,0,1,-1};
int dis[2][160][160];
int main()
{
    int n,m,i,j,bomi,bomj,tim,sti,stj,eni,enj,Min=1<<30,ch=0,cou=0,k,ni,nj;
    scanf("%d %d",&n,&m);
    scanf("%d %d %d %d",&sti,&stj,&eni,&enj);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)scanf("%d",&a[i][j]),dis[0][i][j]=dis[1][i][j]=1<<30;
    dis[0][sti][stj]=0;
    q.push({sti,stj});
    while(!q.empty()){
        i=q.front().i;
        j=q.front().j;
        q.pop();
        for(k=0;k<4;k++){
            ni=i+di[k];
            nj=j+dj[k];
            if(ni<1 || nj<1 || ni>n || nj>m)continue;
            if(a[ni][nj]==0){
                if(dis[0][ni][nj]>dis[0][i][j]+1)dis[0][ni][nj]=dis[0][i][j]+1;
            }
            else{
                if(dis[0][ni][nj]>dis[0][i][j]+1)dis[0][ni][nj]=dis[0][i][j]+1,q.push({ni,nj});
            }
        }
    }
    dis[1][eni][enj]=0;
    q.push({eni,enj});
    while(!q.empty()){
        i=q.front().i;
        j=q.front().j;
        q.pop();
        for(k=0;k<4;k++){
            ni=i+di[k];
            nj=j+dj[k];
            if(ni<1 || nj<1 || ni>n || nj>m)continue;
            if(a[ni][nj]==0){
                if(dis[1][ni][nj]>dis[1][i][j]+1)dis[1][ni][nj]=dis[1][i][j]+1;
            }
            else{
                if(dis[1][ni][nj]>dis[1][i][j]+1)dis[1][ni][nj]=dis[1][i][j]+1,q.push({ni,nj});
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(a[i][j]==0 && dis[0][i][j]!=1<<30 && dis[1][i][j]!=1<<30)cou++;
            if(a[i][j]==0 && dis[0][i][j]!=1<<30 && dis[1][i][j]!=1<<30 && Min>dis[0][i][j]+dis[1][i][j]+1){
                Min=dis[0][i][j]+dis[1][i][j]+1;
            }
        }
    }
    printf("%d \n%d",cou,Min);
    return 0;
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
