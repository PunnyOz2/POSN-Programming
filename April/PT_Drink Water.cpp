/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[25][25],dp[1100000];
int n,k;
int play(int bit){
    if(dp[bit]!=-1) return dp[bit];
    int have[25],dont[25];
    int i,j;
    int cou=0,cou2=0;
    int Min=1e9;
    for(i=0;i<n;i++){
        if(bit&(1<<i))have[cou++]=i;
        else dont[cou2++]=i;
    }
    for(i=0;i<cou;i++){
        for(j=0;j<cou2;j++){
            Min=min(Min,a[dont[j]][have[i]]+play(bit|1<<dont[j]));
        }
    }
    return dp[bit]=Min;
}
int main()
{
	int Q,i,j,cou,Min;
	scanf("%d",&Q);
	while(Q--){
        cou=0;
        scanf("%d %d",&n,&k);
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        int all=pow(2,n);
        memset(dp,-1,sizeof dp);
        dp[all-1]=0;
        Min=1<<30;
        for(i=0;i<all;i++){
            cou=0;
            for(j=0;j<n;j++){
                if(i&(1<<j))cou++;
            }
            if(cou==k){
                Min=min(Min,play(i));
            }
        }
        printf("%d\n",Min);
	}
    return 0;
}
/*
2
5 2
0 5 4 3 2
7 0 4 4 4
3 3 0 1 2
4 3 1 0 5
4 5 5 5 0
6 3
0 7 8 9 1 2
2 0 4 7 8 1
9 2 0 4 2 1
7 9 2 0 8 4
1 1 4 5 0 8
4 5 2 9 6 0
*/
