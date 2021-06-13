/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
PII j[6];
int dp[1000010];
int main()
{
	int w,a,i,Min=1<<30;
	scanf("%d",&w);
	dp[0]=0;
	for(i=1;i<=w+16;i++)dp[i]=1<<30;
	j[0].first=1,j[0].second=500;
	j[1].first=2,j[1].second=800;
	j[2].first=5,j[2].second=1500;
	j[3].first=15,j[3].second=3000;
	for(a=0;a<4;a++){
        for(i=j[a].first;i<=w+16;i++){
            if(dp[i-j[a].first]!=1<<30)
                    dp[i]=min(dp[i],dp[i-j[a].first]+j[a].second);
            if(i>=w)Min=min(dp[i],Min);
        }
	}
	printf("%d",Min);
    return 0;
}
