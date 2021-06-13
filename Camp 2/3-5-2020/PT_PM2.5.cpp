/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char a[1010][1010];
struct A{
    int i,j,w;
};
int di[4]={1,-1,0,0},dj[4]={0,0,1,-1},dis[1010][1010];
queue<A> q;
int main()
{
    int Q,n,m,i,j,w,sum,sti,stj,ch,k,ni,nj;
    scanf("%d",&Q);
    while(Q--){
        sum=0;
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++){
            scanf(" %s",a[i]+1);
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                if(a[i][j]=='E'){sti=i,stj=j;break;}
            }
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                dis[i][j]=1<<30;
            }
        }
        q.push({sti,stj,0});
        dis[sti][stj]=0;
        ch=0;
        while(!q.empty()){
            i=q.front().i;
            j=q.front().j;
            w=q.front().w;
            //printf("%d %d %d\n",i,j,w);
            q.pop();
            if(ch!=0 && ch<=w)continue;
            for(k=0;k<4;k++){
                ni=i+di[k];
                nj=j+dj[k];
                if(ni<1 || nj<1 || ni>n || nj>m)continue;
                if(a[ni][nj]=='#')continue;
                if(dis[ni][nj]<=w+1)continue;
                dis[ni][nj]=w+1;
                if(a[ni][nj]=='S' && ch==0)ch=w+1;
                else sum+=a[ni][nj]-'0';
                q.push({ni,nj,w+1});
            }
        }
        ch=0;
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                if(a[i][j]=='S' && dis[i][j]==1<<30){ch=1;break;}
            }
        }
        if(ch==1)printf("-1\n");
        else printf("%d\n",sum);
        memset(dis,0,sizeof dis);
    }
    return 0;
}
/*
2
5 7
000E0#3
#0##0#0
050#0#0
4#0#0#0
0#0S000
1 4
SE69
*/
