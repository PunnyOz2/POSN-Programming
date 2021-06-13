/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char a[2500][2500];
int dis[2500][2500];
struct A{
    int i,j;
};
queue<A> q;
int di[4]={1,-1,0,0},dj[4]={0,0,1,-1};
int main()
{
    int n,m,i,j,k,nexti,nextj;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf(" %c",&a[i][j]);
            dis[i][j]=1<<30;
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(a[i][j]=='X')q.push({i,j}),dis[i][j]=0;;
        }
    }
    while(!q.empty()){
        i=q.front().i;
        j=q.front().j;
        q.pop();
        for(k=0;k<4;k++){
            nexti=i+di[k];
            nextj=j+dj[k];
            if(nexti>n || nextj>m || nexti<=0 || nextj<=0)continue;
            if(a[nexti][nextj]=='W')continue;
            if(dis[nexti][nextj]>dis[i][j]+1)dis[nexti][nextj]=dis[i][j]+1,q.push({nexti,nextj});
        }
    }
    int cou=0,sum=0;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(a[i][j]=='A'){
                if(dis[i][j]!=1<<30){
                    cou++;
                    sum+=(dis[i][j]*2);
                }
            }
            //printf("%10d ",dis[i][j]);
        }
        //printf("\n");
    }
    printf("%d %d\n",cou,sum);
    return 0;
}
/*
5 9
EEEWEEEEE
EWEWEWEEE
AWXWEWWWE
EWWWEWEEE
EEEEEWAEE

5 5
WEEEE
AWEEW
WEEWW
WEEXE
WWEEE

5 5
WEEEE
AWAEW
WEEWW
WEEXE
WWEEE

5 5
EEEEE
AEAEW
WEEWW
WEEXE
WWEXA
5 5
EEEEE
EEWEE
EWXWE
EEWEE
EEEEA
*/
