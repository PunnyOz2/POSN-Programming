/*
    TASK: Follow
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int pt[1100],dis[1100];
struct B{
    int u,w;
    bool operator<(const B&o)const{
        return w>o.w;
    }
};
int start[1100][1100],stop[1100][1100];
int peatdis[1100][1100];
vector<B>g[1100];
priority_queue<B> dijk;
int main()
{
    int q,n,m,st,en,peatway,i,u,v,w,j,ti,old;
    scanf("%d",&q);
    while(q--){
        memset(start,-1,sizeof start);
        memset(stop,-1,sizeof stop);
        memset(pt,0,sizeof pt);
        memset(peatdis,0,sizeof peatdis);
        scanf("%d %d",&n,&m);
        scanf("%d %d %d %d",&st,&en,&ti,&peatway);
        for(i=0;i<peatway;i++)
            scanf("%d",&pt[i]);
        for(i=0;i<m;i++){
            scanf("%d %d %d",&u,&v,&w);
            g[u].push_back({v,w});
            g[v].push_back({u,w});
            peatdis[u][v]=peatdis[v][u]=w;
        }
        int sta=0;
        old=pt[0];
        for(i=1;i<peatway;i++){
            if(sta!=0)sta++;
            start[old][pt[i]]=start[pt[i]][old]=sta;
            sta+=peatdis[old][pt[i]];
            if(sta-peatdis[old][pt[i]]!=0)sta--;
            stop[old][pt[i]]=stop[pt[i]][old]=sta;
            old=pt[i];
        }
        for(i=1;i<=n;i++){
            dis[i]=1<<29;
        }
        dijk.push({st,ti});
        while(!dijk.empty()){
            u=dijk.top().u,w=dijk.top().w,dijk.pop();
            printf("%d %d\n",u,w);
            if(en==u){printf("%d\n",w+1-ti);break;}
            if(w>dis[u]) continue;
            dis[u]=w;
            for(auto x:g[u]){
                if(w<=stop[u][x.u] && w>=start[u][x.u]) dijk.push({x.u,stop[u][x.u]+1+x.w});
                else dijk.push({x.u,w+x.w});
            }
        }
        for(i=0;i<n;i++) g[i].clear();
        while(!dijk.empty())dijk.pop();
    }
    return 0;
}
/*
2
6 5
1 6 20 4
5 3 2 4
1 2 2
2 3 8
2 4 3
3 5 15
3 6 10
8 9
1 5 5 5
1 2 3 4 5
1 2 8
2 3 10
2 7 4
3 4 23
3 6 5
4 8 4
4 5 5
6 8 3
6 7 40
*/
