/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char a[330][330];
int mark[5][330][330];
int di[16]={-1,-1,0,1,1,1,0,-1,-1,-1,0,1,1,1,0,-1},dj[16]={0,1,1,1,0,-1,-1,-1,0,1,1,1,0,-1,-1,-1};
int dii[4]={1,-1,0,0},djj[4]={0,0,1,-1};
int ch[500];
struct A{
    int i,j,w;
};
queue<A> q;
int dis[5][400][400];
int main()
{
    ch['|']=0;
    ch['/']=1;
    ch['-']=2;
    ch['\\']=3;
    int Q,n,m,i,j,tempi,tempj,k,state,sti,stj,eni,enj,wait,ni,nj,w,temp;
    scanf("%d",&Q);
    while(Q--){
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++){//INPUT
            scanf(" %s",a[i]+1);
        }
        for(i=1;i<=n;i++){//STATE MAKER
            for(j=1;j<=m;j++){
                if(a[i][j]!='S' && a[i][j]!='E' && a[i][j]!='.' && a[i][j]!='#'){
                    //printf("%d %d\n",i,j);
                    for(k=0+ch[a[i][j]];k<8+ch[a[i][j]];k++){
                        tempi=i,tempj=j;
                        state=(k-ch[a[i][j]])%4;
                        while(tempi>=1 && tempj>=1 && tempi<=n &&tempj<=m){
                            //if(state==0)printf(" %d %d\n",tempi,tempj);
                            if(tempi==i && tempj==j)mark[state][tempi][tempj]=1;
                            else{
                                if(a[tempi][tempj]=='E' || a[tempi][tempj]=='#'){break;}
                                if((a[tempi][tempj]=='|' ||a[tempi][tempj]=='/' ||a[tempi][tempj]=='-' ||a[tempi][tempj]=='\\'))break;
                                mark[state][tempi][tempj]=1;
                            }
                            tempi+=di[k];
                            tempj+=dj[k];
                            //printf("   %d %d\n",tempi,tempj);
                        }
                    }
                }
            }
        }
//        for(i=1;i<=n;i++){
//            for(j=1;j<=m;j++)printf("%d ",mark[0][i][j]);
//            printf("\n");
//        }
        for(i=1;i<=n;i++){//check for S
            for(j=1;j<=m;j++){
                if(a[i][j]=='S'){sti=i,stj=j,dis[0][i][j]=0,dis[1][i][j]=dis[2][i][j]=dis[3][i][j]=1<<30;}
                else if(a[i][j]=='E'){eni=i,enj=j,dis[0][i][j]=dis[1][i][j]=dis[2][i][j]=dis[3][i][j]=1<<30;}
                else dis[0][i][j]=dis[1][i][j]=dis[2][i][j]=dis[3][i][j]=1<<30;
            }
        }
        q.push({sti,stj,0});
        while(!q.empty()){
            i=q.front().i;
            j=q.front().j;
            w=q.front().w;
            //printf("%d %d %d %d\n",i,j,wait,dis[wait][i][j]);
            q.pop();
            for(k=0;k<4;k++){
                ni=i+dii[k];
                nj=j+djj[k];
                if(ni<1 || nj<1 || ni>n || nj>m)continue;
                if(a[ni][nj]=='#')continue;
                if(mark[(w+1)%4][ni][nj]!=0)continue;
                if(dis[(w+1)%4][ni][nj]>dis[w%4][i][j]+1){
//                    printf(" %d %d\n",ni,nj);
                    dis[(w+1)%4][ni][nj]=dis[w%4][i][j]+1;
                    q.push({ni,nj,w+1});
                }
            }
        }
//        for(i=1;i<=n;i++){
//            for(j=1;j<=m;j++){
//                printf("%d ",dis[0][i][j]);
//            }
//            printf("\n");
//        }
        temp=min(dis[0][eni][enj],min(dis[1][eni][enj],min(dis[2][eni][enj],dis[3][eni][enj])));
        if(temp==1<<30)printf("-1\n");
        else printf("%d\n",temp);
        memset(mark,0,sizeof mark);
    }
    return 0;
}
/*
2
5 5
S....
.....
#....
.....
|...E

*/
