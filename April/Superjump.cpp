/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u;
    double w;
    int state;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
struct B{
    int u,w;
};
priority_queue<A> q;
int ans[100100];
vector<B> g[100100];
double dis[100100][2];
int main()
{
	int n,m,i,u,w,v,state;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
	}
	q.push({0,0,0});
    for(i=1;i<n;i++)dis[i][0]=dis[i][1]=1<<30;
	while(!q.empty()){
        u=q.top().u,state=q.top().state,q.pop();
        if(u==n-1 && state==1){
            printf("%.2lf\n",dis[u][state]);
            break;
        }
        for(auto x:g[u]){
            if(dis[x.u][state]>dis[u][state]+x.w)dis[x.u][state]=dis[u][state]+x.w,q.push({x.u,dis[x.u][state],state});
            if(state==0 && dis[x.u][state+1]>dis[u][state]+0.14)dis[x.u][state+1]=dis[u][state]+0.14,q.push({x.u,dis[x.u][state+1],state+1});
        }
	}
    return 0;
}
/*
6 8
0 1 1
0 2 3
1 2 2
2 4 1
2 3 2
2 5 4
3 4 1
3 5 1
*/
