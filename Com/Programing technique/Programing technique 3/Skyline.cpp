/*
    TASK: Skyline
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1000];
int main()
{
    int i,n,l,r,h;
    scanf("%d",&n);
    while(n--){
        scanf("%d %d %d",&l,&h,&r);
        for(i=l;i<r;i++)
            if(dp[i]<h)
                dp[i]=h;
    }
    h=0;
    for(i=0;i<300;i++){
        if(dp[i]!=h){
            printf("%d %d ",i,dp[i]);
            h = dp[i];
        }
    }

    return 0;
}
/*
8
1 11 5
2 6 7
12 7 16
14 3 25
19 18 22
3 13 9
23 13 29
24 4 28
*/
