/*
    TASK: Bie wedding
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,w;
    bool operator<(const A&o) const{
        if(w!=o.w) return w>o.w;
        else       return v>o.v;
    }
};
priority_queue< A > q;
vector< A > g[100];
int dis[100],mark[100];
int main()
{
    int m,w,i;
    char u,v;
    scanf("%d",&m);
    while(m--){
        scanf(" %c %c %d",&u,&v,&w);
        g[u-'A'].push_back({v-'A',w});
        g[v-'A'].push_back({u-'A',w});
    }
	q.push({25,0});
	for(i=0;i<100;i++)
        dis[i]=1<<30;
    dis[25]=0;
    while(!q.empty()){
        i=q.top().v,w=q.top().w;
        q.pop();
        if(mark[i]) continue;
        mark[i]=1;
        if(i<25){
            printf("%c %d\n",i+'A',w);
            return 0;
        }
        for(auto x:g[i]){
            if(mark[x.v]!=0) continue;
            if(dis[i]+x.w<dis[x.v])
                dis[x.v]=dis[i]+x.w;
            q.push({x.v,dis[x.v]});

        }
    }
    return 0;
}
/*
5
A d 6
B d 3
C e 9
d Z 8
e Z 3
*/
