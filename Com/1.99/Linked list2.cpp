/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[500100],dp[500100];
int main()
{
    int n,idx,cnt=0,i,num;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&num);
        idx = upper_bound(dp,dp+cnt,num)-dp;
        if(idx>=1 && dp[idx-1]==num) continue;
        if(idx==cnt) cnt++;
        dp[idx]=num;
    }
	printf("%d\n",n-cnt);
    return 0;
}
// 4 2 4 1 3
