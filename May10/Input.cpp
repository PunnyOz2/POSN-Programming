/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[1020],mark[1020],dp[1010][1010];
int main()
{
    int q,n,m,num,i,j,idx;
    scanf("%d",&q);
    while(q--){
        memset(mark,0,sizeof mark);
        memset(dp,0,sizeof dp);
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            a[i]+=a[i-1];
        }
        mark[1]=1,mark[a[n]]=n;
        dp[1][1]=1;
        for(i=1;i<=m;i++){
            scanf("%d",&num);
            idx=lower_bound(a+1,a+n+1,num)-a;
            mark[num]=idx;
        }
        //for(i=1;i<=a[n];i++)printf("%d ",mark[i]);
        for(i=1;i<=a[n];i++){
            if(mark[i]!=0)dp[i][mark[i]]+=dp[i-1][mark[i]-1]%9901+dp[i-1][mark[i]]%9901;
            else{
                for(j=1;j<=n;j++){
                    dp[i][j]+=dp[i-1][j]%9901+dp[i-1][j-1]%9901;
                }
            }
        }
        printf("%d\n",dp[a[n]][n]%9901);
    }
    return 0;
}
/*
2
3 2
3 1 7
2 4

3 2
2 3 2
2 4
*/
