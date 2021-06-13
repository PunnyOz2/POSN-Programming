/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char a[510][510];
int mark[510][510][4];
struct A{
    int i,j,w,di;
};
queue<A> q;
int di[4]={-1,0,1,0},dj[4]={0,1,0,-1};
int main()
{
    int n,m,i,j,dir,k,w;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf(" %c",&a[i][j]);
        }
    }
    int sti,stj;
    scanf("%d %d",&sti,&stj);
    if(a[sti][stj]=='S'){printf("U\n0\n");return 0;}
    int Max=-1;
    int ans;
    for(k=0;k<4;k++){
        memset(mark,0,sizeof mark);
        q.push({sti,stj,1,k});
        mark[sti][stj][k]=1;
        while(!q.empty()){
            i=q.front().i;
            j=q.front().j;
            dir=q.front().di;
            w=q.front().w;
            q.pop();
            if(i+di[dir]<=0 || j+dj[dir]<=0 || i+di[dir]>n || j+dj[dir]>m || a[i+di[dir]][j+dj[dir]]=='S'){
                //printf("%d %d %d %d %d\n",i,j,i+di[dir],j+dj[dir],w);
                if(w>Max)Max=w,ans=k;
                while(!q.empty())q.pop();
                break;
            }
            if(mark[i+di[dir]][j+dj[dir]][dir]==1){
                //printf("%d %d\n",i,j);
                //printf("%d %d\n",i+di[dir],j+dj[dir]);
                if(k==0)printf("U\n");
                if(k==1)printf("R\n");
                if(k==2)printf("D\n");
                if(k==3)printf("L\n");
                printf("Infinity\n");
                return 0;
            }
            if(a[i+di[dir]][j+dj[dir]]=='/'){
                if(dir==0){
                    q.push({i+di[dir],j+dj[dir],w+1,1});
                }
                if(dir==1){
                    q.push({i+di[dir],j+dj[dir],w+1,0});
                }
                if(dir==2){
                    q.push({i+di[dir],j+dj[dir],w+1,3});
                }
                if(dir==3){
                    q.push({i+di[dir],j+dj[dir],w+1,2});
                }
            }
            else if(a[i+di[dir]][j+dj[dir]]=='\\'){
                if(dir==0){
                    q.push({i+di[dir],j+dj[dir],w+1,3});
                }
                if(dir==1){
                    q.push({i+di[dir],j+dj[dir],w+1,2});
                }
                if(dir==2){
                    q.push({i+di[dir],j+dj[dir],w+1,1});
                }
                if(dir==3){
                    q.push({i+di[dir],j+dj[dir],w+1,0});
                }
            }
            else{
                q.push({i+di[dir],j+dj[dir],w+1,dir});
            }
            mark[i+di[dir]][j+dj[dir]][dir]=1;
        }
    }
    if(ans==0)printf("U\n");
    if(ans==1)printf("R\n");
    if(ans==2)printf("D\n");
    if(ans==3)printf("L\n");
    printf("%d\n",Max);
    return 0;
}
/*
5 5
../.\
.....
.S...
...S.
\.../
3 3

5 7
/.....\
../..\.
\...../
/.....\
\.\.../
3 3
*/
