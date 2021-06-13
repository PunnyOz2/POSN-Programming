/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,w;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
priority_queue<A> q;
vector <pair<int,int> >g[100100];
int dis[2][10010];
int main()
{
	int n,m,st,en,u,v,w,i,j;
	scanf("%d %d",&n,&m);
	scanf("%d %d",&st,&en);
	for(i=0;i<m;i++){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w});
	}
	for(i=0;i<=1;i++){
        for(j=1;j<=n;j++){dis[i][j]=1<<30;}
	}
	dis[0][st]=0;
	//dis[1][st]=0;
	q.push({st,0});
	while(!q.empty()){
        u=q.top().u,w=q.top().w,q.pop();
        for(auto x:g[u]){
            if(dis[0][x.first]>w+x.second){
                dis[1][x.first]=dis[0][x.first];
                dis[0][x.first]=w+x.second;
                q.push({x.first,dis[0][x.first]});
            }
            else if(dis[1][x.first]>w+x.second){
                dis[1][x.first]=w+x.second;
                q.push({x.first,dis[1][x.first]});
            }
        }
	}
	printf("%d\n",dis[1][en]);
    return 0;
}
