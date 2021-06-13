/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1010][1010],a[1010],n;
int play(int now,int last){
    if(now<1||now>n) return 1000000000;
    if(dp[now][last]) return dp[now][last];
    if(now==n) return a[now];
    return dp[now][last] = a[now]+min(play(now+last+1,last+1),play(now-last,last));
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    printf("%d\n",play(2,1));
    return 0;
}
/*
6
1
2
3
4
5
6
*/
