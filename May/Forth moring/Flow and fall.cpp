/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[110][110];
int dis[110][110];
int di[4]={1,-1,0,0},dj[4]={0,0,1,-1};
struct A{
    int num,i,j;
    bool operator<(const A & o)const{
        return num>o.num;
    }
};
priority_queue<A> q;
int main()
{
    int n,m,i,j,Max=0,k,nexti,nextj;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)scanf("%d",&a[i][j]),q.push({a[i][j],i,j}),dis[i][j]=1;
    while(!q.empty()){
        i=q.top().i;
        j=q.top().j;
        q.pop();
        for(k=0;k<4;k++){
            nexti=i+di[k];
            nextj=j+dj[k];
            if(nexti>n || nextj>m || nexti<=0 || nextj<=0)continue;
            if(a[nexti][nextj]>a[i][j])dis[nexti][nextj]=max(dis[nexti][nextj],dis[i][j]+1);
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            Max=max(Max,dis[i][j]);
        }
    }
    printf("%d\n",Max);
    return 0;
}
/*
3 3
1 2 3
4 5 6
7 8 9
2 3
2 1 2
1 2 1

3 3
3 5 4
6 1 3
9 2 8
*/
