/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1000100];
int main()
{
	int n,i,num,tail;
	scanf("%d",&n);
	dp[0]=1;
	while(n--){
        scanf("%d",&num);
        for(i=n;i-num>=0;i--){
            if(num==0) dp[i]++;
            else if(dp[i-num]!=0) dp[i]++;
        }
	}
	scanf("%d",&tail);
	printf("%d",dp[tail]-1);
    return 0;
}
/*
5
1
3
4
3
0
4
*/
