#include <bits/stdc++.h>
using namespace std;
int a[120][120];
int dis[120][120][2525];
int di[7]={1,1,-1,-1,0,0},dj1[7]={0,1,0,1,1,-1},dj2[7]={-1,0,-1,0,1,-1};
struct A{
    int i,j,w;
};
queue<A> q;
int main(){
    int n,m,i,j,k,w,ni,nj;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&a[i][j]);
            for(k=0;k<=2520;k++){
                dis[i][j][k]=1<<30;
            }
        }
    }
    if(a[(n-1)/2-1][0]==1)dis[(n-1)/2-1][0][1]=1,q.push({(n-1)/2-1,0, 1});
    if(a[(n-1)/2][0]==1)  dis[(n-1)/2][0][1]=1,  q.push({(n-1)/2,0, 1});
    if(a[(n-1)/2+1][0]==1)dis[(n-1)/2+1][0][1]=1,q.push({(n-1)/2+1,0, 1});
    while(!q.empty()){
        i=q.front().i;
        j=q.front().j;
        w=q.front().w;
        //printf("%d %d %d\n",i,j,w);
        q.pop();
        if(j==m-1 && i==(n-1)/2){
            printf("%d\n",w);
            break;
        }
        if(i%2==0){
            for(k=0;k<6;k++){
                ni=i+di[k];
                nj=j+dj1[k];
                if(ni<0 || nj<0 || ni>=n || nj>=m)continue;
                if(a[ni][nj]!=0 && (w+1)%a[ni][nj]==0 && dis[ni][nj][(w+1)%2520]>w+1){
                    dis[ni][nj][(w+1)%2520]=w+1;
                    q.push({ni,nj,w+1});
                }
            }
        }
        else{
            for(k=0;k<6;k++){
                ni=i+di[k];
                nj=j+dj2[k];
                if(ni<0 || nj<0 || ni>=n || nj>=m)continue;
                if(a[ni][nj]!=0 && (w+1)%a[ni][nj]==0 && dis[ni][nj][(w+1)%2520]>w+1){
                    dis[ni][nj][(w+1)%2520]=w+1;
                    q.push({ni,nj,w+1});
                }
            }
        }
    }
}
/*
5 4
1 1 3 8
0 1 1 0
1 6 5 7
1 3 2 3
2 5 2 0
*/
