/*
    TASK: Tower
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dp[10100];
vector<int> g[10100];
int main()
{
	int k,n,m,r,s,i;
	scanf("%d %d %d",&k,&n,&m);
	while(m--){
        scanf("%d %d",&r,&s);
        g[r].push_back(s);
	}
	for(i=0;i<=n;i++) dp[i]=1<<30;
	dp[1]=0;
	for(i=1;i<=n;i++){
        for(auto x:g[i]){
            dp[x]=min(dp[x],dp[i]+1);
        }
	}
	for(i=n;i>=1;i--){
        if(dp[i]<=k){ printf("%d",i);break;}
	}
    return 0;
}
/*
2 6 5
1 2
1 3
2 5
3 4
5 6
*/
