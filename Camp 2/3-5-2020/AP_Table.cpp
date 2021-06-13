/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char a[35][35];
int di[4]={1,-1,0,0},dj[4]={0,0,1,-1};
struct A{
    int i,j,w;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
priority_queue<A> q;
int dis[55][55];
int main()
{
    int Q,Max=0,n,x,y,ii,jj,i,j,k,ni,nj,w;
    scanf("%d",&Q);
    while(Q--){
        Max=0;
        scanf("%d %d %d",&n,&x,&y);
        for(i=1;i<=n;i++){
            scanf(" %s",a[i]+1);
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                for(ii=1;ii<=n;ii++){
                    for(jj=1;jj<=n;jj++){
                        dis[ii][jj]=1<<30;
                    }
                }
                q.push({i,j,0});
                dis[i][j]=0;
                while(!q.empty()){
                    ii=q.top().i;
                    jj=q.top().j;
                    q.pop();
                    for(k=0;k<4;k++){
                        ni=ii+di[k];
                        nj=jj+dj[k];
                        if(ni<1 || nj<1 || ni>n || nj>n)continue;
                        if(a[ni][nj]==a[ii][jj])w=x;
                        else w=y;
                        if(dis[ni][nj]>dis[ii][jj]+w){
                            dis[ni][nj]=dis[ii][jj]+w;
                            q.push({ni,nj,dis[ni][nj]});
                        }
                    }
                }
                for(ii=1;ii<=n;ii++){
                    for(jj=1;jj<=n;jj++){
                        Max=max(Max,dis[ii][jj]);
                    }
                }
            }
        }
        printf("%d\n",Max);
    }
    return 0;
}
/*

*/
