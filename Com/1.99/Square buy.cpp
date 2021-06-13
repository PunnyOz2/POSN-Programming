/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dp[100100];
int main()
{
	int i,j,q,z,m;
	for(i=0;i<=100000;i++)
        dp[i]=100000;
    dp[0]=0;
    for(i=0;i<=100000;i++){
        for(j=1;j<=317;j++){
            if(i+j*j<=100000)
                dp[i+j*j]=min(dp[i+j*j],dp[i]+1);
        }
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&z,&m);
        printf("%d\n",dp[z]%m);
    }
    return 0;
}
/*
4
1 5
10 4
16 3
10 2
*/
