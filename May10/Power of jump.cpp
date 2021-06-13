/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int a[5100];
pair<int,int> tmp[5010];
int pos[5010];
int dp[5100][103];
    int q,n,k;
void update(int a,int b,int c){
    int i;
    for(i=a;i<=n;i+=(i&-i)){
        dp[i][b]=(dp[i][b]+c)%1000000007;
    }
}
long long query(int a,int b){
    int i;
    long long sum=0;
    for(i=a;i>0;i-=(i&-i)){
        sum+=dp[i][b];
        sum%=mod;
    }
    return sum;
}
int main()
{
    int i,j;
    scanf("%d",&q);
    while(q--){
        memset(dp,0,sizeof dp);
        scanf("%d %d",&n,&k);
        for(i=1;i<=n;i++)scanf("%d",&a[i]),tmp[i]={a[i],-i};
        sort(tmp+1,tmp+1+n);
        for(i=1;i<=n;i++)pos[-tmp[i].second]=i;
        update(pos[1],0,1);
        for(i=2;i<=n;i++){
            for(j=0;j<=k;j++){
                long long cnt=0;
                cnt=query(pos[i],j);
                if(j>0){
                    cnt=(cnt+query(n,j-1)-query(pos[i],j-1))%mod;
                }
                if(cnt<0)cnt+=mod;
                update(pos[i],j,cnt);
            }
        }
        long long ans=0;
        for(i=0;i<=k;i++){
            ans+=(query(pos[n],i)-query(pos[n]-1,i))%mod;
        }
        if(ans<0)ans+=mod;
        printf("%lld\n",ans);
    }
    return 0;
}
/*
2
5 0
1
2
3
4
5
5 1
4
5
1
2
3
*/
