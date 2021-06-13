/*
    TASK: Locked room
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,w,state; //0=close 1=open
    bool operator<(const A&o) const{
        return w>o.w;
    }
};
priority_queue<A> q;
int dis[100][100][2],a[100][100],di[4]={1,-1,0,0},dj[4]={0,0,1,-1};
int main()
{
    int i,j,n,k,sti,stj,eni,enj,ii,jj,nowstate,nextstate,noww;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
	scanf("%d %d %d %d",&sti,&stj,&eni,&enj);
	q.push({sti,stj,0});
	memset(dis,-1,sizeof dis);
	while(!q.empty()){
        i=q.top().i,j=q.top().j,noww=q.top().w,nowstate=q.top().state;
        q.pop();
        if(i==eni&&j==enj&&nowstate==1){
            printf("%d\n",noww); return 0;
        }
        for(k=0;k<4;k++){
            ii=i+di[k],jj=j+dj[k];
            nextstate=nowstate;
            if(ii<1||jj<1||ii>n||jj>n) continue;
            if(a[ii][jj]<0) nextstate^=1;
            if(dis[ii][jj][nextstate]!=-1) continue;
            dis[ii][jj][nextstate]=noww+abs(a[ii][jj]);
            q.push({ii,jj,dis[ii][jj][nextstate],nextstate});

        }
	}
    return 0;
}
/*
4
1 1 9 1
1 4 1 -3
1 9 2 1
1 1 3 1
3 2 3 3
*/
