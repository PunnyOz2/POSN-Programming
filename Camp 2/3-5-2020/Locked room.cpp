/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,w,st;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
int dis[2][60][60],di[4]={1,-1,0,0},dj[4]={0,0,1,-1};
int a[60][60];
priority_queue<A> q;
int main()
{
    int n,i,j,ii,jj,eni,enj,sti,stj,w,st,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            dis[0][i][j]=dis[1][i][j]=1<<30;
        }
    }
    scanf("%d %d %d %d",&sti,&stj,&eni,&enj);
    dis[0][sti][stj]=0;
    q.push({sti,stj,0,0});
    while(!q.empty()){
        i=q.top().i;
        j=q.top().j;
        w=q.top().w;
        st=q.top().st;
        q.pop();
        for(k=0;k<4;k++){
            ii=i+di[k];
            jj=j+dj[k];
            if(ii<1 || jj<1 || ii>n || jj>n)continue;
            if(a[ii][jj]<0){
                if(dis[1^st][ii][jj]>dis[st][i][j]-a[ii][jj])dis[st^1][ii][jj]=dis[st][i][j]-a[ii][jj],q.push({ii,jj,dis[st^1][ii][jj],st^1});
            }
            else{
                if(dis[st][ii][jj]>dis[st][i][j]+a[ii][jj])dis[st][ii][jj]=dis[st][i][j]+a[ii][jj],q.push({ii,jj,dis[st][ii][jj],st});
            }
        }
    }
    printf("%d\n",dis[1][eni][enj]);
    return 0;
}
