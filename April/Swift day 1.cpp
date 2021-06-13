/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1000100];
int main()
{
	int m,n,i,u,v,cou;
	scanf("%d %d",&m,&n);
	for(i=0;i<m;i++){
        scanf("%d %d",&u,&v);
        dp[u]=max(dp[u],v);
	}
	int idx=0;
	int ans=0;
	while(dp[idx]<n){
        ans++;
        cou=dp[idx];
        for(i=idx;i<=cou+1;i++){
            if(dp[i]>idx)idx=i;
        }
	}
	printf("%d\n",ans);
    return 0;
}
/*
4 10
1 5
3 7
4 8
8 10
*/
