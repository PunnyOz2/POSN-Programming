/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dp[22000];
int main()
{
	int q,u,v,n,distance,i,j,jj;
	scanf("%d",&q);
	while(q--){
        scanf("%d %d %d",&u,&v,&n);
        distance=abs(u-v);
        for(i=1;i<=distance;i++)dp[i]=1<<30;
        for(i=0;i<n;i++){
            scanf("%d",&j);
            for(jj=j;jj<=distance;jj++){
                if(dp[jj-j]!=1<<30)dp[jj]=min(dp[jj],dp[jj-j]+1);
            }
        }
        if(dp[distance]!=1<<30) printf("%d\n",dp[distance]);
        else printf("-1\n");
        }
    return 0;
}
/*
2
15 1 3
2 5 7
2 5 1
4
*/
