/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int cou=1;
int in[500100],out[500100];
vector<int> g[500100];
long long a[500100];
long long fen[1000100];
void dfs(int n){
    in[n]=cou++;
    for(auto x:g[n]){
        dfs(x);
    }
    out[n]=cou++;
}
int main()
{
	int n,m,i,par,node,j,mon;
	char command;
	scanf("%d %d %lld",&n,&m,&a[1]);
	for(i=2;i<=n;i++){
        scanf("%lld %d",&a[i],&par);
        g[par].push_back(i);
	}
	dfs(1);
	while(m--){
        scanf(" %c",&command);
        if(command=='u'){
            scanf("%d",&node);
            cou=0;
            for(j=out[node];j>0;j-=(j&-j)){
                cou+=fen[j];
            }
            printf("%d\n",cou+a[node]);
        }
        if(command=='p'){
            scanf("%d %d",&node,&mon);
            for(j=in[node]+1;j<=n*2;j+=(j&-j)){
                fen[j]+=mon;
            }
            for(j=out[node];j<=n*2;j+=(j&-j)){
                fen[j]-=mon;
            }
        }
	}
    return 0;
}
