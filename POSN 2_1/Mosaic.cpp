/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> g[1000100];
queue<int> q;
map<int,int> mp;
map<int,int> mpname;
int mark[2010][2010];
int mark2[1000100];
int main()
{
	int n,k,i,u,v,cou,ch,Min=10000000;
	scanf("%d %d",&n,&k);
	cou=1;
	for(i=0;i<k;i++){
        scanf("%d %d",&u,&v);
        if(mpname[u]==0)mpname[u]=cou++;
        if(mpname[v]==0)mpname[v]=cou++;
        g[u].push_back(v);
        g[v].push_back(u);
	}
	q.push(1);
	for(i=1;i<=1000000;i++){
        sort(g[i].begin(),g[i].end());
	}
	mark2[1]=1;
	while(!q.empty()){
        u=q.front(),q.pop();
        //sort(g[u].begin(),g[u].end());
        for(cou=1;cou<=2000;cou++){
            if(mark[mpname[u]][cou]==0){break;}
        }
        mp[u]=cou;
        for(auto x:g[u]){
            if(mark2[x]==0){
                q.push(x);
                mark2[x]=1;
            }
            mark[mpname[x]][cou]=1;
        }
	}
	for(auto x:mp){
        printf("%d\n",x.second);
	}
    return 0;
}
/*
4 4
1 999
999 9999
9999 99999
99999 1
*/
