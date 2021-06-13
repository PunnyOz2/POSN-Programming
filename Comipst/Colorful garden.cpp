/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000003
int c,i,a[1200],u,v;
vector<int> g[1200];
int dp[1200][1200],mark[1200][1200],j,ans;
int main()
{
    int n,m,k;
    scanf("%d %d %d",&n,&m,&c);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<m;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(i=0;i<n;i++){
        dp[i][1<<a[i]]=1;
    }
        for(k=0;k<=(1<<c)-1;k++){
            for(j=0;j<n;j++){
                if(dp[j][k]==0 || mark[j][k]==1)continue;
                for(auto x:g[j]){
                    if((k&(1<<a[x]))==0)dp[x][k|(1<<a[x])]+=dp[j][k],dp[x][k|(1<<a[x])]%=MOD,mark[j][k]=1;
                }
            }
        }
    for(i=0;i<n;i++){
        ans+=dp[i][(1<<c)-1];
        ans%=MOD;
    }
    printf("%d\n",ans);
    return 0;
}
/*
4 3 4
0 1 2 3
0 1
1 2
2 3
*/
