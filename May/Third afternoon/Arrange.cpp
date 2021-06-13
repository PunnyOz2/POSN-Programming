#include<bits/stdc++.h>
using namespace std;
int dp[10010],a[16000];
int main()
{
    int q,n,m,i,num,j;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&m);
        memset(dp,0,sizeof dp);
        dp[0]=1;
        for(i=0;i<m;i++)
            scanf("%d",&a[i]);
        sort(a,a+m);
        for(i=0;i<m-1;i++){
            for(j=n-1;j>=0;j--){
                if(dp[j]==1 && j+a[i]<n)
                    dp[j+a[i]]=1;
            }
        }
        for(i=n;i>=0;i--){
            if(dp[i]==1){
                printf("%d\n",n-a[m-1]-i);
                break;
            }
        }
    }
    return 0;
}
/*
2
4 3
1 100000 2
5 4
1 2 3 4
*/
