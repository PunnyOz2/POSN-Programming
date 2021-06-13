/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int di[4]={1,-1,0,0},dj[4]={0,0,1,-1};
struct A{
    int i,j,i2,j2;
};
struct B{
    int i,j;
};
queue<A> q;
queue<B> q2;
char a[40][40];
int dis[40][40][40][40],dis2[40][40][40][40];
int main()
{
    int Q,n,m,ni,nj,ni2,nj2,i,j,ii,jj,sti,stj,stii,stjj,i2,j2,k,Min,Min2;
    scanf("%d",&Q);
    while(Q--){
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                for(ii=1;ii<=n;ii++){
                    for(jj=1;jj<=m;jj++){
                        dis2[i][j][ii][jj]=1<<30;
                        dis[i][j][ii][jj]=1<<30;
                    }
                }
            }
        }
        for(i=1;i<=n;i++){
            scanf(" %s",a[i]+1);
            for(j=1;j<=m;j++){
                if(a[i][j]=='A')sti=i,stj=j;
                if(a[i][j]=='B')stii=i,stjj=j;
            }
        }
        dis[sti][stj][stii][stjj]=0;
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                if(a[i][j]!='#')q2.push({i,j}),dis2[i][j][i][j]=0;
                //printf("  %d %d\n",i,j);
                while(!q2.empty()){
                    ii=q2.front().i;
                    jj=q2.front().j;
                    //printf("%d %d\n",ii,jj);
                    q2.pop();
                    for(k=0;k<4;k++){
                        ni=ii+di[k];
                        nj=jj+dj[k];
                        if(ni<1  || nj<1  || ni>n  || nj>m  || a[ni][nj]  =='#')continue;
                        if(dis2[i][j][ni][nj]<=dis2[i][j][ii][jj]+1)continue;
                        dis2[i][j][ni][nj]=dis2[i][j][ii][jj]+1;
                        q2.push({ni,nj});
                    }
                }
            }
        }
        if(dis2[sti][stj][stii][stjj]==1<<30){printf("-1 0\n");continue;}
        //printf("hi\n");
        q.push({sti,stj,stii,stjj});
        while(!q.empty()){
            i=q.front().i,j=q.front().j,i2=q.front().i2,j2=q.front().j2;
            q.pop();
            for(k=0;k<4;k++){
                ni=i+di[k],nj=j+dj[k],ni2=i2-di[k],nj2=j2-dj[k];
                if(ni<1  || nj<1  || ni>n  || nj>m  || a[ni][nj]  =='#')ni=i,nj=j;
                if(ni2<1 || nj2<1 || ni2>n || nj2>m || a[ni2][nj2]=='#')ni2=i2,nj2=j2;
                if(   dis[ni][nj][ni2][nj2]  >  dis[i][j][i2][j2]+1  ){
                    dis[ni][nj][ni2][nj2]=dis[i][j][i2][j2]+1;
                    q.push({ni,nj,ni2,nj2});
                }
            }
        }
//        for(i=1;i<=n;i++){
//            for(j=1;j<=m;j++){
//                printf("%d ",dis2[1][1][i][j]);
//            }
//            printf("\n");
//        }
        Min=1<<30;
        Min2=1<<30;
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                for(ii=1;ii<=n;ii++){
                    for(jj=1;jj<=m;jj++){
                        //if(ii==i && jj==j)continue;
                        if(Min>dis2[i][j][ii][jj] && dis[i][j][ii][jj]!=1<<30){
                            Min=dis2[i][j][ii][jj];
                            Min2=dis[i][j][ii][jj];
                            //printf("%d %d %d %d\n",i,j,ii,jj);
                        }
                        else if(Min==dis2[i][j][ii][jj] && Min2>dis[i][j][ii][jj]){
                            Min2=dis[i][j][ii][jj];
                        }
                    }
                }
            }
        }
        if(Min==1<<30)printf("-1 0\n");
        else printf("%d %d\n",Min,Min2);
    }
    return 0;
}
/*
4
2 5
A....
....B
1 5
A.#.B
1 5
A...B
3 5
A....
###..
###.B

2
3 3
A..
.#.
..B
*/
