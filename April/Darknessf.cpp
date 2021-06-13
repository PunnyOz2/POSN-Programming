/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int di[4]={1,-1,0,0},dj[4]={0,0,1,-1};
struct A{
    int i,j,w,fuel;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
priority_queue<A> q;
int dis[10100][10100];
char a[10100][10100];
int main()
{
	int n,m,k,i,j,sti,stj,eni,enj,fuel,w,kk;
	scanf("%d %d %d",&n,&m,&kk);
	for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf(" %c",&a[i][j]);
            if(a[i][j]=='A')sti=i,stj=j;
            if(a[i][j]=='B')eni=i,enj=j;
            dis[i][j]=1<<30;
        }
	}
	q.push({sti,stj,0,kk});
	dis[sti][stj]=0;
	while(!q.empty()){
        i=q.top().i,j=q.top().j,w=q.top().w,fuel=q.top().fuel,q.pop();
        if(i==eni && j==enj)break;
        for(k=0;k<4;k++){
            if(i+di[k]>=1 && i+di[k]<=n && j+dj[k]>=1 && j+dj[k]<=m&& dis[i+di[k]][j+dj[k]]>dis[i][j]+1 && fuel>0){
                    dis[i+di[k]][j+dj[k]]=dis[i][j]+1;
                    if(a[i+di[k]][j+dj[k]]!='X')
                        q.push({i+di[k],j+dj[k],dis[i+di[k]][j+dj[k]],fuel-1});
                    else q.push({i+di[k],j+dj[k],dis[i+di[k]][j+dj[k]],kk});
            }
        }
	}
	if(dis[eni][enj]==1<<30)printf("-1\n");
	else printf("%d\n",dis[eni][enj]);
    return 0;
}
/*
4 3 2
X.A
...
X..
.B.
*/
