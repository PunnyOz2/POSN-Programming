/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,sti,stj,eni,enj,w,k,bit,nexti,nextj;
char a[600][600];
int dis[600][600][10];
int di[4]={1,-1,0,0},dj[4]={0,0,1,-1};
struct A{
    int i,j,w,bit;
};
queue<A> q;
int main()
{
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf(" %c",&a[i][j]);
            if(a[i][j]=='S')sti=i,stj=j;
            if(a[i][j]=='E')eni=i,enj=j;
            for(k=0;k<=7;k++){
                dis[i][j][k]=1<<30;
            }
        }
    }
    dis[sti][stj][0]=0;
    q.push({sti,stj,0,0});
    while(!q.empty()){
        i=q.front().i;
        j=q.front().j;
        w=q.front().w;
        bit=q.front().bit;
        //printf("%d %d %d\n",i,j,bit);
        q.pop();
        if(i==eni&&j==enj){printf("%d\n",dis[i][j][bit]);goto jump;}
        for(k=0;k<4;k++){
            nexti=i+di[k],nextj=j+dj[k];
            if(nexti>n || nextj>m || nexti<=0 || nextj<=0)continue;
            if(a[nexti][nextj]=='#')continue;
            if(a[nexti][nextj]=='P' && ((bit&(1<<0))==0))continue;
            if(a[nexti][nextj]=='J' && ((bit&(1<<1))==0))continue;
            if(a[nexti][nextj]=='B' && ((bit&(1<<2))==0))continue;
            if(a[nexti][nextj]=='p' && dis[nexti][nextj][(bit|(1<<0))]>w+1)dis[nexti][nextj][(bit|(1<<0))]=w+1,q.push({nexti,nextj,w+1,bit|(1<<0)});
            else if(a[nexti][nextj]=='j' && dis[nexti][nextj][(bit|(1<<1))]>w+1)dis[nexti][nextj][(bit|(1<<1))]=w+1,q.push({nexti,nextj,w+1,bit|(1<<1)});
            else if(a[nexti][nextj]=='b' && dis[nexti][nextj][(bit|(1<<2))]>w+1)dis[nexti][nextj][(bit|(1<<2))]=w+1,q.push({nexti,nextj,w+1,bit|(1<<2)});
            else if(dis[nexti][nextj][bit]>w+1)dis[nexti][nextj][bit]=w+1,q.push({nexti,nextj,w+1,bit});
        }
    }
    printf("-1\n");
    jump:;
    return 0;
}
/*
2 5
S.J.b
.jB.E

2 5
SJJBb
.j.#E

2 5
SJjjJ
jJj.E
*/
