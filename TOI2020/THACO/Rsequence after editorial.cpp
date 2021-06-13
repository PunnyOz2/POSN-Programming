#include<bits/stdc++.h>
using namespace std;
long long dp[500100],a[500100],d[500100],p[500100];
unordered_map<long long,long long> mp[500100];
int main(){
	long long n,i,now,sum=0,j,k;
	scanf("%lld",&n);
	for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
	}
	k=0;
	for(i=1;i<=n;i++){
        if(mp[d[i-1]].find(a[i])!=mp[d[i-1]].end()){
            p[i]=mp[d[i-1]][a[i]];
            d[i]=d[p[i]-1];
        }
        else{
            d[i]=k;
            k++;
        }
        mp[d[i]][a[i]]=i;
	}
	for(i=1;i<=n;i++){
        if(p[i]!=0){
            dp[i]++;
            dp[i]+=dp[p[i]-1];
            sum+=dp[i];
        }
	}
	printf("%lld\n",sum);
}
/*
5
1 1 1 2 2

1 1 2 2 1

1 1 2 2 3 2 2 1

10
1 2 1 3 3 2 2 1 2 2
*/
