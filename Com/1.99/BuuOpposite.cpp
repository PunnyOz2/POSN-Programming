/*
    TASK: BUU opposite
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,k,l,w;
};
queue< A > q;
int dis[33][33][33][33],mark[33][33][33][33];
int di[4]={0,0,1,-1},dj[4]={-1,1,0,0};
int di2[4]={0,0,-1,1},dj2[4]={1,-1,0,0};
char a[35][35];
int main()
{
	int Q,r,c,i,j,k,l,ii,jj,kk,ll,sti,stj,eni,enj,mi,ans;
	int nowi,nowk,nowj,nowl,nowdis;
	scanf("%d",&Q);
	while(Q--){
        scanf("%d %d",&r,&c);
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                scanf(" %c",&a[i][j]);
                if(a[i][j]=='A') sti=i,stj=j;
                if(a[i][j]=='B') eni=i,enj=j;
            }
        }
        memset(dis,-1,sizeof dis);
        memset(mark,0,sizeof mark);
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                if(a[i][j]=='#') continue;
                q.push({i,j,0,0,0});
                dis[i][j][i][j]=0;
                while(!q.empty()){
                    nowi=q.front().i,nowj=q.front().j;
                    q.pop();
                    for(k=0;k<4;k++){
                        ii=nowi+di[k],jj=nowj+dj[k];
                        if(ii<0||jj<0||ii>=r||jj>=c) continue;
                        if(a[ii][jj]=='#') continue;
                        if(dis[i][j][ii][jj]!=-1) continue;
                        dis[i][j][ii][jj]=dis[i][j][nowi][nowj]+1;
                        q.push({ii,jj,0,0,0});
                    }
                }
            }
        }
        mi=1<<30,ans=0;
        q.push({sti,stj,eni,enj,0});
        while(!q.empty()){
            nowi=q.front().i,nowj=q.front().j,nowk=q.front().k;
            nowl=q.front().l,nowdis=q.front().w;q.pop();
            if(dis[nowi][nowj][nowk][nowl]<mi)
                mi=dis[nowi][nowj][nowk][nowl],ans=nowdis;
            for(k=0;k<4;k++){
                ii=nowi+di[k],jj=nowj+dj[k],kk=nowk+di2[k];
                ll=nowl+dj2[k];
                if(ii<0||jj<0||ii>=r||jj>=c||a[ii][jj]=='#')
                    ii=nowi,jj=nowj;
                if(kk<0||ll<0||kk>=r||ll>=c||a[kk][ll]=='#')
                    kk=nowk,ll=nowl;
                if(mark[ii][jj][kk][ll]) continue;
                if(dis[ii][jj][kk][ll]==-1) continue;
                mark[ii][jj][kk][ll]=1;
                q.push({ii,jj,kk,ll,nowdis+1});
            }
        }
        if(dis[sti][stj][eni][enj]==-1) printf("-1 0 \n");
        else printf("%d %d\n",mi,ans);
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
*/
