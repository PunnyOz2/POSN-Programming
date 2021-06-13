/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char a[2010][2010];
long long dis[2010][2010];
long long di[4]={1,-1,0,0},dj[4]={0,0,1,-1};
struct A{
    long long i,j;
};
queue<A> q,q2;
int main()
{
    long long n,m,cou,sum,i,j,ni,nj,k,ii,jj;
    scanf("%lld %lld",&n,&m);
    for(i=1;i<=n;i++){
        scanf(" %s",a[i]+1);
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            dis[i][j]=1<<30;
        }
    }
    for(ii=1;ii<=n;ii++){
        for(jj=1;jj<=m;jj++){
            if(a[ii][jj]=='X')dis[ii][jj]=0,q.push({ii,jj});
            if(a[ii][jj]=='A')q2.push({ii,jj});
        }
    }
    while(!q.empty()){
        i=q.front().i;
        j=q.front().j;
        q.pop();
        for(k=0;k<4;k++){
            ni=i+di[k];
            nj=j+dj[k];
            if(ni<1 || nj<1 || ni>n || nj>m)continue;
            if(a[ni][nj]=='W')continue;
            if(dis[ni][nj]>dis[i][j]+1)dis[ni][nj]=dis[i][j]+1,q.push({ni,nj});
        }
    }
    cou=0;sum=0;
    while(!q2.empty()){
        i=q2.front().i;
        j=q2.front().j;
        q2.pop();
        if(dis[i][j]!=1<<30){
            cou++;
            sum+=dis[i][j]*2;
        }
    }
    printf("%lld %lld",cou,sum);
    return 0;
}
