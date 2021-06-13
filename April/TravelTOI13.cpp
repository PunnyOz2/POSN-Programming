/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int disst[10100];
int disen[10100];
vector<pair<int,int>> g[10100];
queue<pair<int,int>> q;
int main()
{
	int n,m,st,en,k,i,j,kk,u,v,w;
	scanf("%d %d",&n,&m);
	scanf("%d %d %d",&st,&en,&kk);
	for(i=0;i<n;i++)
        for(j=0;j<n;j++)disst[i]=disen[i]=1<<25;
	for(i=0;i<m;i++){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
	}
	q.push({st,0});
	disst[st]=0;
	while(!q.empty()){
        u=q.front().first,w=q.front().second,q.pop();
        for(auto x:g[u]){
            if(disst[x.first]>w+x.second)disst[x.first]=w+x.second,q.push({x.first,disst[x.first]});
        }
	}
	q.push({en,0});
	disen[en]=0;
	while(!q.empty()){
        u=q.front().first,w=q.front().second,q.pop();
        for(auto x:g[u]){
            if(disen[x.first]>w+x.second)disen[x.first]=w+x.second,q.push({x.first,disen[x.first]});
        }
	}
	if(disst[en]<=kk || disen[st]<=kk)printf("%d %d 0\n",en,disst[en]);
	else{
        int cango=st,Maxdis=0,left=disst[en];
        for(k=0;k<n;k++){
            if(disst[k]>kk)continue;
            if(Maxdis <=disst[k] && left>disen[k])cango=k,Maxdis=disst[k],left=disen[k];
        }
        printf("%d %d %d\n",cango,Maxdis,left);
	}
    return 0;
}
/*
8 11
0 5 45

0 1 10
0 2 10
1 3 10
1 5 70
2 3 10
2 4 30
2 6 10
3 5 30
4 5 20
6 7 15
7 5 20
*/
