/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[280];
int mark[200];
float ansall;
vector<pair<int,int>> g[300];
int dfsch(int n){
    if(n=='Y') return 1;
    mark[n]=1;
    for(auto x:g[n]){
        if(mark[x.first]==0)
            if(dfsch(x.first)==1) return 1;
    }
    return 0;
}
void dfs(int n){
    if(n=='Y') return;
    int i=0;
    int ans;
    mark[n]=1;
    for(auto x:g[n]){
        if(mark[x.first]==0){
        a[++i]=x.second;
        ans=x.first;
        //printf("%c %c %f\n",n,x.first,a[i]);
        }
    }
    sort(a+1,a+i+1);
    if(i%2==1)printf("%c %c %.1f\n",n,ans,(float)a[(i+1)/2]),ansall+=(float)a[(i+1)/2];
    else printf("%c %c %.1f\n",n,ans,(a[i/2+1]+a[i/2])/2.0),ansall+=((a[i/2+1]+a[i/2])/2.0);
    dfs(ans);
}
int main()
{
	int n,i,w;
	char u,v;
	scanf("%d",&n);
	for(i=0;i<n;i++){
        scanf(" %c %c %d",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
	}
	if(dfsch('X')==1){
        memset(mark,0,sizeof mark);
        dfs('X');
        printf("%.1f\n",ansall);
	}
	else printf("broken\n");
    return 0;
}
/*
6
X a 1
a b 4
b a 1
b Y 3
b Y 2
Y b 6
*/
