/*
    TASK: Plantation
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dis[33][33],mark[33][33];
char d[33][33];
struct A{
    int i,j,w;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
priority_queue<A> q;
int di[4]={1,-1,0,0},dj[4]={0,0,1,-1};
int main()
{
    int Q,n,a,b,cost,Max=0,i,j,k,ii,jj,w;
    scanf("%d",&Q);
    while(Q--){
        Max=0;
        scanf("%d %d %d",&n,&a,&b);
        for(i=1;i<=n;i++)
            scanf(" %s", &d[i][1]);
            for(j=1;j<=n;j++)
                dis[i][j]=1<<29;
        int cou=1;
        for(ii=1;ii<=n;ii++){
            for(jj=1;jj<=n;jj++){
                q.push({ii,jj,0});
                while(!q.empty()){
                    i=q.top().i,j=q.top().j,w=q.top().w,q.pop();
                    if(mark[i][j]==cou || w>=dis[i][j])continue;
                    dis[i][j]=w;
                    mark[i][j]=cou;
                    for(k=0;k<4;k++){
                        if(i+di[k]<=n&&i+di[k]>=1&&j+dj[k]<=n&&j+dj[k]>=1&&d[i][j]!=d[i+di[k]][j+dj[k]])q.push({i+di[k],j+dj[k],w+b});
                        if(i+di[k]<=n&&i+di[k]>=1&&j+dj[k]<=n&&j+dj[k]>=1&&d[i][j]==d[i+di[k]][j+dj[k]])q.push({i+di[k],j+dj[k],w+a});
                    }
                }
                for(i=1;i<=n;i++){
                    for(j=1;j<=n;j++){
                            Max=max(Max,dis[i][j]);
                    }
                }
                for(i=1;i<=n;i++)
                    for(j=1;j<=n;j++)dis[i][j]=1<<29;
                cou++;
            }
        }
        printf("%d\n",Max);

    }
    return 0;
}
/*
1
3 1 2
AAA
ABA
AAB
*/
