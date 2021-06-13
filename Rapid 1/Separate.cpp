/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[550][300][300];
vector<pair<long long,long long>> level[2000];
int chek(pair<long long,long long> A ,pair<long long,long long> B ){
    if(A.second == B.second && A.first==B.first+1)return 0;
    if(A.second == B.second+1 && A.first==B.first)return 0;
    return 1;
}
int main()
{
	long long n,m,i,j,k,l,mm;
	scanf("%lld %lld",&n,&mm);
	for(i=n;i>0;i--){
        for(j=mm;j>0;j--){
            level[i+j-1].push_back({i,j});
        }
	}
	dp[1][0][0]=1;
	for(i=2;i<=n+mm-1;i++){
        long long sz=level[i].size(),psz=level[i-1].size();
        for(j=0;j<sz;j++){
            for(k=0;k<sz;k++){
                for(l=-1;l<=1;l++){
                    for(m=-1;m<=1;m++){
                        long long idx_j = j+l,idx_k =k+m;
                        if(idx_j<0 || idx_j>=psz || idx_k<0 || idx_k>=psz)continue;
                        if(chek(level[i][j],level[i-1][idx_j]) || chek(level[i][k],level[i-1][idx_k])) continue;
                        if(j==k && idx_j==idx_k)continue;
                        dp[i][j][k]=(dp[i][j][k]%1000000007+dp[i-1][idx_j][idx_k]%1000000007)%1000000007;
                    }
                }
            }
        }
	}
	printf("%lld\n",dp[(n+mm-1)][0][0]);
    return 0;
}
