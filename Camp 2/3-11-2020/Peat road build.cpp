/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[5010][4],dis[2][1010];
struct A{
    int u,w,odd;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
priority_queue<A> q;
vector<A> g[1010];
int main()
{
    int n,m,l,r,mid,i,u,w,odd,Min;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
    }

    for(i=1;i<=m;i++){
        g[a[i][0]].push_back({a[i][1],a[i][2],0});
        g[a[i][1]].push_back({a[i][0],a[i][2],0});
    }
    for(i=1;i<=n;i++){
        dis[0][i]=dis[1][i]=1<<30;
    }
    q.push({1,0,1});
    dis[1][1]=0;
    while(!q.empty()){
        u=q.top().u;
        w=q.top().w;
        odd=q.top().odd;
        q.pop();
        for(auto x:g[u]){
            if(dis[(odd+1)%2][x.u]>dis[odd][u]+x.w){
                dis[(odd+1)%2][x.u]=dis[odd][u]+x.w;
                q.push({x.u,dis[(odd+1)][x.u],(odd+1)%2});
            }
        }
    }
    for(i=1;i<=n;i++){
        g[i].clear();
    }
    Min=dis[0][n];
    l=1;
    r=m;
    while(l<r){
        mid=(l+r)/2;
        //printf("%d ",mid);
        for(i=1;i<=mid;i++){
            g[a[i][0]].push_back({a[i][1],a[i][2],0});
            g[a[i][1]].push_back({a[i][0],a[i][2],0});
        }
        for(i=1;i<=n;i++){
            dis[0][i]=dis[1][i]=1<<30;
        }
        q.push({1,0,1});
        dis[1][1]=0;
        while(!q.empty()){
            u=q.top().u;
            w=q.top().w;
            odd=q.top().odd;
            q.pop();
            for(auto x:g[u]){
                if(dis[(odd+1)%2][x.u]>dis[odd][u]+x.w){
                    dis[(odd+1)%2][x.u]=dis[odd][u]+x.w;
                    q.push({x.u,dis[(odd+1)%2][x.u],(odd+1)%2});
                }
            }
        }
        //printf("%d\n",dis[0][n]);
        if(dis[0][n]<=Min)r=mid;
        else l=mid+1;
        for(i=1;i<=n;i++){
            g[i].clear();
        }
    }
    printf("%d %d\n",l,Min);
    return 0;
}
/*
5 10
4 5 7
3 2 1
3 5 5
5 2 5
1 4 6
2 1 1
4 3 7
1 3 7
4 2 4
1 5 8
*/
