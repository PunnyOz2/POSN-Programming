/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dp[100005];
int main()
{
	int i,n,t,num,ans=0,ans2=0,j;
	for(i=2;i<=100000;i++)
        dp[i]=1e9;
    scanf("%d %d",&n,&t);
    for(i=0;i<n;i++){
        scanf("%d",&num);
        if(dp[num]!=1e9){
            ans+=dp[num],ans2++;
        }
        else{
            dp[num]=1;
            for(j=2*num;j<=100000;j+=num)
                dp[j]=min(dp[j],dp[num]+dp[j/num]);
        }
    }
    if(t==1)printf("%d\n",ans2);
    else printf("%d %d\n",ans2,ans);
    return 0;
}
