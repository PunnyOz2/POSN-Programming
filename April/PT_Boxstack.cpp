/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[1200][2],dp[1200];
int main()
{
	int q,n,cou,i,j;
	scanf("%d",&q);
	while(q--){
        cou=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d %d",&a[i][0],&a[i][1]);//wi & si
        }
        dp[0]=1<<30;
        int ans=-1;
        for(i=1;i<=n;i++){
            for(j=i;j>=1;j--){
                if(dp[j-1]-a[i][0]>=0){
                dp[j]=max(dp[j],min(dp[j-1]-a[i][0],a[i][1]));
                ans=max(ans,j);
                }
            }
        }
        printf("%d\n",ans);
        memset(dp,0,sizeof dp);
	}
    return 0;
}
/*
1
5
19 15
7 13
5 7
6 8
1 2
*/
