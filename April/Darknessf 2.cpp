/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,cou;
};
struct B{
    int u,w;
    bool operator<(const B&o)const{
        return w>o.w;
    }
};
priority_queue<B> q;
vector<A>vil;
vector<pair<int,int>> g[2005];
int dis[2500];
int main()
{
	int n,m,k,i,j,sti,stj,eni,enj;
	char MAP[11000];
	scanf("%d %d %d",&n,&m,&k);
	int cou=1;
	for(i=1;i<=n;i++){
        scanf(" %s",MAP+1);
        for(j=1;j<=m;j++){
            if(MAP[j]=='A')sti=i,stj=j;
            if(MAP[j]=='B')eni=i,enj=j;
            if(MAP[j]=='X')vil.push_back({i,j,cou}),cou++;
        }
	}
	vil.push_back({sti,stj,0});vil.push_back({eni,enj,cou});
	if(abs(sti-eni)+abs(stj-enj)<=k){
        printf("%d\n",abs(sti-eni)+abs(stj-enj));
        return 0;
    }
	for(i=0;i<vil.size();i++){
            dis[vil[i].cou]=1<<30;
	    for(j=i+1;j<vil.size();j++){
                if(abs(vil[i].i-vil[j].i)+abs(vil[i].j-vil[j].j)<=k){
                    g[vil[i].cou].push_back({vil[j].cou,abs(vil[i].i-vil[j].i)+abs(vil[i].j-vil[j].j)});
                    g[vil[j].cou].push_back({vil[i].cou,abs(vil[i].i-vil[j].i)+abs(vil[i].j-vil[j].j)});
                }
        }
    }
	int w,u;
	q.push({0,0});
	dis[cou]=1<<30;
	dis[0]=0;
	while(!q.empty()){
        u=q.top().u,w=q.top().w,q.pop();
        if(u==cou){printf("%d\n",w);return 0;}
        if(w>dis[u])continue;
        for(auto x:g[u]){
            if(w+x.second<dis[x.first]){
                dis[x.first]=w+x.second,q.push({x.first,w+x.second});
            }
        }
	}
	printf("-1\n");
    return 0;
}
/*
4 3 2
X.A
...
X..
.B.

3 3 1
A..
X..
.B.
*/
