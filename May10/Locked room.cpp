/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,w,bit;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
priority_queue<A> q;
vector<A> g[35];
char ar[105][105];
int key[105][105];
int door[105][105];
int dist[105][105];
int dis[35][1<<16];
queue<pair<int,int>> bfs;
int di[4]={1,-1,0,0},dj[4]={0,0,1,-1};
int main()
{
    int n,m,ii,jj,i,j,sti,stj,eni,enj,k,a,b,c,d,l,ni,nj,u,w,bit;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf(" %s",ar[i]+1);
    scanf("%d %d %d %d %d",&sti,&stj,&eni,&enj,&k);
    memset(key,-1,sizeof key);
    memset(door,-1,sizeof door);
    for(i=0;i<k;i++){
        scanf("%d %d %d %d",&a,&b,&c,&d);
        key[a][b]=door[c][d]=i;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            int now;
            if(key[i][j]!=-1)now=key[i][j];
            else if(door[i][j]!=-1)now=k+door[i][j];
            else if(sti==i&&stj==j)now=k*2;
            else if(eni==i&&enj==j)now=k*2+1;
            else continue;
            memset(dist,-1,sizeof dist);
            dist[i][j]=0;
            bfs.push({i,j});
            while(!bfs.empty()){
                ii=bfs.front().first,jj=bfs.front().second;
                //printf("%d %d\n",ii,jj);
                bfs.pop();
                for(l=0;l<4;l++){
                    ni=ii+di[l],nj=jj+dj[l];
                    if(ni>n || ni<=0 || nj<=0 || nj>n || ar[ni][nj]=='#'|| dist[ni][nj]!=-1)continue;
                    dist[ni][nj]=dist[ii][jj]+1;
                    if(key[ni][nj]!=-1)g[now].push_back({key[ni][nj],dist[ni][nj],1<<key[ni][nj]});
                    if(door[ni][nj]!=-1)g[now].push_back({k+door[ni][nj],dist[ni][nj],0});
                    if(sti==ni&&stj==nj)g[now].push_back({k*2,dist[ni][nj],0});
                    if(eni==ni&&enj==nj)g[now].push_back({k*2+1,dist[ni][nj],0});
                    if(door[ni][nj]==-1)bfs.push({ni,nj});
                }
            }
        }
    }
    for(i=0;i<=k*2+1;i++){
        for(j=0;j<(1<<k);j++){
            dis[i][j]=1<<30;
        }
    }
    dis[k*2][0]=0;
    q.push({k*2,0,0});
    while(!q.empty()){
        u=q.top().u;
        w=q.top().w;
        bit=q.top().bit;
        q.pop();
        for(auto x:g[u]){
            if(x.u>=k && x.u<k*2){
                if(bit&(1<<(x.u-k))){
                    if(dis[x.u][bit]>w+x.w){
                        dis[x.u][bit]=w+x.w;
                        q.push({x.u,dis[x.u][bit],bit});
                    }
                }
            }
            else{
                if(dis[x.u][bit|x.bit]>x.w+w){
                    dis[x.u][bit|x.bit]=x.w+w;
                    q.push({x.u,dis[x.u][bit|x.bit],bit|x.bit});
                }
            }
        }
    }
    int ans=1<<30;
    for(i=0;i<(1<<k);i++){
        ans=min(ans,dis[k*2+1][i]);
    }
    if(ans==1<<30)printf("-1\n");
    else printf("%d\n",ans);
    return 0;
}
/*
5
..#..
...#.
...#.
...#.
.....
1 1 1 5 2
1 2 4 5
4 1 3 5
*/
