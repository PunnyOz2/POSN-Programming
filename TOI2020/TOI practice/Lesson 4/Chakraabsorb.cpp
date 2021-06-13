#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,w;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
priority_queue<A> q;
int a[1010][1010],mark[1010][1010];
int di[]={1,-1,0,0},dj[]={0,0,1,-1};
int main(){
    int n,i,j,sti=0,stj,eni,enj,w,k,ni,nj;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            if(a[i][j]==0 && sti==0)sti=i,stj=j;
            else if(a[i][j]==0)eni=i,enj=j;
        }
    }
    //printf("HI\n");
    mark[sti][stj]=1;
    q.push({sti,stj,a[i][j]});
    while(!q.empty()){
        i=q.top().i;
        j=q.top().j;
        w=q.top().w;
        if(i==eni && j==enj){printf("%d\n",w);break;}
        q.pop();
        for(k=0;k<4;k++){
            ni=i+di[k];
            nj=j+dj[k];
            if(ni<1 || nj<1 || ni>n || nj>n)continue;
            if(mark[ni][nj]!=0)continue;
            mark[ni][nj]=1;
            q.push({ni,nj,max(w,a[ni][nj])});
        }
    }
    return 0;
}
/*
5
1 1 1 0 1
3 1 1 1 1
0 3 4 3 2
1 1 1 4 1
1 4 2 2 2
*/
