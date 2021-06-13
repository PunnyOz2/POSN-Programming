/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char str[250];
long long dp[3][250][250];
long long exceed[2][202][202];
long long play(long long state,long long l,long long r){
    if(l>r)return 0;
    if(dp[state][l][r]!=-1)return dp[state][l][r];
    if((r-l+1)==2){
        long long res;
        if(str[l]=='?'&&str[r]=='?')res=3;
        else if(str[l]=='?'||str[r]=='?'){
            res= str[l]=='('||str[l]=='{'||str[l]=='['||str[r]==')'||str[r]=='}'||str[r]==']';
        }
        else{
            res= str[l]=='(' && str[r]==')'|| str[l]=='{' && str[r]=='}' || str[l]=='[' && str[r]==']';
        }
        return dp[0][l][r]=dp[1][l][r]=res;
    }
    if(state==0){
        long long res;
        if(str[l]=='?'&&str[r]=='?')res=3;
        else if(str[l]=='?'||str[r]=='?'){
            res= str[l]=='('||str[l]=='{'||str[l]=='['||str[r]==')'||str[r]=='}'||str[r]==']';
        }
        else{
            res= str[l]=='(' && str[r]==')'|| str[l]=='{' && str[r]=='}' || str[l]=='[' && str[r]==']';
        }
        return dp[0][l][r]=(res*play(1,l+1,r-1))%100000;
    }
    else if(state==1){
        long long ans=0,i;
        for(i=l+1;i<=r-2;i++){
            if(exceed[1][i+1][r]==1)ans+=play(0,l,i)*(play(1,i+1,r)%100000);
            else ans+=play(0,l,i)*play(1,i+1,r);
        }
        if(ans+play(0,l,r)>=100000)exceed[1][l][r]=1;
        return dp[1][l][r]=(ans+play(0,l,r))%100000;
    }
}
int main()
{
	long long n,ans,i;
	scanf("%lld",&n);
	scanf(" %s",str+1);
	memset(dp,-1,sizeof dp);
	ans=play(1,1,n);
	if(exceed[1][1][n]==1)ans%=100000,printf("%05lld\n",ans);
	else printf("%lld\n",ans);
    return 0;
}
/*
10
(?([?)]?}?
*/
