/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> g[500100];
int mon;
long long a[500100];
void dfs(int n){
    for(auto x:g[n]){
        a[n]+=mon;
        dfs(x);
    }
    return;
}
int main()
{
	int n,m,i,par,node;
	char command;
	scanf("%d %d %lld",&n,&m,&a[1]);
	for(i=2;i<=n;i++){
        scanf("%lld %d",&a[i],&par);
        g[par].push_back(i);
	}
	while(m--){
        scanf(" %c",&command);
        if(command=='u'){
            scanf("%d",&node);
            printf("%lld\n",a[node]);
        }
        if(command=='p'){
            scanf("%d %d",&node,&mon);
            dfs(node);
        }
	}
    return 0;
}
/*
5 6
4
2 1
6 1
7 1
3 4
u 3
p 1 -1
u 3
p 4 5
u 5
u 1
*/
