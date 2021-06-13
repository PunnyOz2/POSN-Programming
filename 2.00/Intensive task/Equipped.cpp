/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dp[300];
int main()
{
    int n,k,p,i,w,r,m;
    scanf("%d %d",&n,&k);
    p=1<<k;
    for(i=1;i<=p;i++)
        dp[i]=1<<30;
    while(n--){
        scanf("%d",&w);
        m=0;
        for(i=0;i<k;i++){
            scanf("%d",&r);
            m*=2;
            if(r==1) m++;
        }
        for(i=0;i<=p;i++)
            dp[i|m]=min(dp[i|m],dp[i]+w);
    }
    printf("%d\n",dp[p-1]);
    return 0;
}
/*
5 3
10 1 0 1
30 0 1 1
5 1 0 0
4 0 0 1
150 1 1 1
*/
