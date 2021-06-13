/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[1<<12],mask[1<<12];
long long play(long long bit){
    if(dp[bit]!=-1)return dp[bit];
    if(__builtin_popcount(bit)==1) return dp[bit]=0;
    int i;
    for(i=1;i<bit;i++){
        if((i&bit)!=i)continue;
        long long cost=max((~mask[i])&mask[bit^i],(~mask[bit^i])&mask[i]);
        dp[bit]=max(dp[bit],play(i)+play(bit^i)+cost);
    }
    return dp[bit];
}
int main()
{
    int n,q,m,i,j,a,d;
	scanf("%d",&q);
	while(q--){
        memset(dp,-1,sizeof dp);
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++){
            scanf("%d",&d);
            for(j=0;j<d;j++)scanf("%d",&a),mask[1<<i]|=(1ll<<(a-1));
        }
        for(i=1;i<(1<<n);i++){
            for(j=0;j<n;j++){
                if(i&(1<<j)){
                    mask[i]=mask[1<<j]^mask[i^(1<<j)];
                    break;
                }
            }
        }
        printf("%lld\n",play((1<<n)-1));
        memset(mask,0,sizeof mask);
	}
    return 0;
}
/*
1
3 4
2 1 3
1 2
3 1 2 4
*/
