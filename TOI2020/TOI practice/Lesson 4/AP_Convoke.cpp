#include<bits/stdc++.h>
using namespace std;
int dis[203][(1<<15)+3],disf[203][203];
int need[203];
struct B{
    int u,w,mark;
    bool operator<(const B&o)const{
        return w>o.w;
    }
};
priority_queue<B>q;
int main(){
    int n,m,k,i,num,u,v,w,j,mark,kk;
    scanf("%d %d %d",&n,&m,&k);
    for(i=0;i<k;i++)scanf("%d",&num),need[i]=num;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)if(i!=j)disf[i][j]=1<<25;
    for(i=0;i<m;i++){
        scanf("%d %d %d",&u,&v,&w);
        disf[u][v]=disf[v][u]=w;
    }
    for(kk=1;kk<=n;kk++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(disf[i][j]>disf[i][kk]+disf[kk][j])disf[i][j]=disf[i][kk]+disf[kk][j];
//    for(i=1;i<=n;i++){
//        for(j=1;j<=n;j++)printf("%d ",disf[i][j]);
//    printf("%d\n");}
    for(i=1;i<=n;i++){
        for(j=0;j<(1<<k);j++)dis[i][j]=1<<30;
    }
    dis[1][0]=0;
    q.push({1,0,0});
    while(!q.empty()){
        u=q.top().u;
        mark=q.top().mark;
        //printf("%d %d\n",u,mark);
        q.pop();
        if(u==n && mark==(1<<k)-1){
            printf("%d\n",dis[n][(1<<k)-1]);
            break;
        }
        for(i=0;i<k;i++){
            if(u==need[i])continue;
            if(dis[need[i]][mark|(1<<i)]>dis[u][mark]+disf[u][need[i]]){
                dis[need[i]][mark|(1<<i)]=dis[u][mark]+disf[u][need[i]];
                q.push({need[i],dis[need[i]][mark|(1<<i)],mark|(1<<i)});
            }
        }
        if(u!=1 && dis[1][mark]>dis[u][mark]+disf[u][1]){
            dis[1][mark]=dis[u][mark]+disf[u][1];
            q.push({1,dis[1][mark],mark});
        }
        if(u!=n && dis[n][mark]>dis[u][mark]+disf[u][n]){
            dis[n][mark]=dis[u][mark]+disf[u][n];
            q.push({n,dis[n][mark],mark});
        }
    }
    return 0;
}
/*
7 10 2
4 5
1 2 1
1 3 2
4 1 2
2 4 2
3 4 1
4 5 1
4 6 3
5 7 1
7 6 2
4 7 4
*/
