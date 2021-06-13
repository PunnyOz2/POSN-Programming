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
};
queue<A> q;
queue<A> q2;
char a[2010][2010];
int dis[2010][2010];
int di[4]={1,-1,0,0},dj[4]={0,0,1,-1};
int main()
{
    int n,m,i,j,sum=0,ii,jj,w,k,cou=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf(" %c",&a[i][j]);
            if(a[i][j]=='X') q.push({i,j,0});
            else if(a[i][j]=='A') q2.push({i,j,0});
            dis[i][j]=100000000;
        }
    }
    while(!q.empty()){
        ii=q.front().i,jj=q.front().j,w=q.front().w,q.pop();
        if(w>=dis[ii][jj]) continue;
        if(w<dis[ii][jj])dis[ii][jj]=w;
        for(k=0;k<4;k++){
            if(ii+di[k]<=n&&ii+di[k]>=1&&jj+dj[k]<=m&&jj+dj[k]>=1&&(a[ii+di[k]][jj+dj[k]]=='E'||a[ii+di[k]][jj+dj[k]]=='A'))q.push({ii+di[k],jj+dj[k],w+1});
        }
    }
    while(!q2.empty()){
        ii=q2.front().i,jj=q2.front().j,q2.pop();
        if(dis[ii][jj]!=100000000)sum+=(dis[ii][jj]*2),cou++;
    }
    printf("%d %d",cou,sum);

    return 0;
}
/*
5 5
EEEEE
AEAEW
WEEWW
WEEXE
WWEXA

5 5
WEEEE
AWAEW
WEEWW
WEEXE
WWEEE

5 9
EEEWEEEEE
EWEWEWEEE
AWXWEWWWE
EWWWEWEEE
EEEEEWAEE
*/
