/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[110][110],di[4]={1,-1,0,0},dj[4]={0,0,1,-1};
struct A{
    int i,j,w,mark;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
priority_queue<A> q;
int dis[2][110][110];
int main()
{
    int n,m,hr,mi,i,j,w,mark,sti,stj,eni,enj,k,ni,nj,temp;
    scanf("%d %d",&n,&m);
    scanf("%d %d %d %d",&sti,&stj,&eni,&enj);
    scanf("%d:%d",&hr,&mi);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            dis[0][i][j]=dis[1][i][j]=1<<30;
        }
    }
    dis[0][sti][stj]=a[sti][stj];
    if(a[sti][stj]<0){
        dis[1][sti][stj]=a[i][j];
        dis[0][sti][stj]=0;
        q.push({sti,stj,dis[1][sti][stj],1});
    }
    q.push({sti,stj,dis[0][sti][stj],0});
    while(!q.empty()){
        i=q.top().i;
        j=q.top().j;
        w=q.top().w;
        mark=q.top().mark;
        //printf("%d %d %d %d\n",i,j,w,mark);
        q.pop();
        for(k=0;k<4;k++){
            ni=i+di[k];
            nj=j+dj[k];
            if(ni<1 || nj<1 || ni>n || nj>m)continue;
            if(a[ni][nj]<0 && mark==0 && dis[1][ni][nj]>dis[0][i][j]+a[ni][nj]){
                dis[1][ni][nj]=dis[0][i][j]+a[ni][nj];
                q.push({ni,nj,dis[1][ni][nj],1});
            }
            if(a[ni][nj]<0 && dis[mark][ni][nj]>dis[mark][i][j]){
                dis[mark][ni][nj]=dis[mark][i][j];
                q.push({ni,nj,dis[mark][ni][nj],mark});
            }
            if(a[ni][nj]>0 && dis[mark][ni][nj]>dis[mark][i][j]+a[ni][nj]){
                dis[mark][ni][nj]=dis[mark][i][j]+a[ni][nj];
                q.push({ni,nj,dis[mark][ni][nj],mark});
            }
        }
    }
    temp=min(dis[0][eni][enj],dis[1][eni][enj]);
    //temp=-220;
    if(temp>0){
        temp%=720;
        hr+=temp/60;
        mi+=temp%60;
        if(mi>=60)mi-=60,hr++;
        if(hr>=12)hr-=12;
    }
    else{
        temp*=-1;
        temp%=720;
        hr-=temp/60;
        mi-=temp%60;
        if(mi<0)mi+=60,hr--;
        if(hr<0)hr+=12;
    }
    printf("%02d:%02d\n",hr,mi);
    return 0;
}
/*
3 3 1 1 3 3
00:00
4 6 7
8 6 3
10 4 -30
*/
