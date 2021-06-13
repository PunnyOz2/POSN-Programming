/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char a[50][50];
int dis[50][50];
struct A{
    int i,j;
};
queue<A> q;
int di[4]={1,-1,0,0},dj[4]={0,0,1,-1};
int main()
{
	int Q,n,m,k,i,j,ii,jj,sti,stj,eni,enj,t,cou=0;
	scanf("%d",&Q);
	while(Q--){
        cou=0;
        scanf("%d %d %d",&n,&m,&t);
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++)dis[i][j]=1<<25;
        }
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                scanf(" %c",&a[i][j]);
        scanf("%d %d %d %d",&sti,&stj,&eni,&enj);
        q.push({sti,stj});
        dis[sti][stj]=0;
        while(!q.empty()){
            ii=q.front().i,jj=q.front().j,q.front(),q.pop();
            cou++;
            for(k=0;k<4;k++){
                if(ii+di[k]<=n && ii+di[k]>=1 && jj+dj[k]<=m && jj+dj[k]>=1 && a[ii+di[k]][jj+dj[k]]!='#'&& dis[ii+di[k]][jj+dj[k]]>dis[ii][jj]+1)dis[ii+di[k]][jj+dj[k]]=dis[ii][jj]+1,q.push({ii+di[k],jj+dj[k]});
            }
        }
        if(dis[eni][enj]<=t){
            int left=t-dis[eni][enj];
            int other=cou-dis[eni][enj]-1;
            int cou2=0;
            while(left>=2 && other>=1){
                cou2++;
                other--;
                left-=2;
            }
            printf("%d\n",cou2+dis[eni][enj]+1);
        }
        else printf("-1\n");
	}
    return 0;
}
/*
3
5 8 9
#..#..#.
.#...##.
##.##..#
...##.##
##.#..##
4 3 2 4
4 5 100
.....
.####
...#.
#.##.
3 3 1 3
3 5 2
.....
.####
.....
3 3 1 3
*/
