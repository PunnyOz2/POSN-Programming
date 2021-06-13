/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,w;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
priority_queue<A> q;
int di[4]={1,-1,0,0},dj[4]={0,0,1,-1};
int a[1010][1010];
int dis[1010][1010];
int main()
{
	int n,m,k,i,j,Min=1<<30,w,nexti,nextj,kk;
	scanf("%d %d %d",&n,&m,&k);
	for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf("%d",&a[i][j]),dis[i][j]=1<<30;
    for(i=1;i<k;i++)q.push({i,1,a[i][1]}),dis[i][1]=a[i][1];
    while(!q.empty()){
        i=q.top().i,j=q.top().j,w=q.top().w,q.pop();
        for(kk=0;kk<4;kk++){
            nexti=i+di[kk],nextj=j+dj[kk];
            if(nexti<1 || nexti>n || nextj<1 || nextj>m)continue;
            if(dis[nexti][nextj]<=w+a[nexti][nextj])continue;
            if(nexti==k && nextj==1)continue;
            dis[nexti][nextj]=w+a[nexti][nextj];
            q.push({nexti,nextj,w+a[nexti][nextj]});
        }
    }
//    for(i=1;i<=n;i++){
//        for(j=1;j<=m;j++)printf("%9d ",dis[i][j]);
//        printf("\n");
//    }
    for(i=k+1;i<=n;i++)Min=min(Min,dis[i][1]);
    printf("%d\n",Min);
    return 0;
}
/*
5 5 3
999 999 999 999 999
1 1 999 999 999
999 1 1 1 999
999 4 1 2 999
1 1 1 1 1
*/
