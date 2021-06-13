/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int row[20],col[20],dp[20][20],path[20][20];
void pr(int l,int r){
    if(l==r){
        printf("A%d",l+1);
        return;
    }
    printf("(");
    pr(l,path[l][r]);
    printf(" x ");
    pr(path[l][r]+1,r);
    printf(")");

}
int main()
{
	int n,i,j,k,mi,now,m;
	scanf("%d",&n);
	for(i=0;i<n;i++)
        scanf("%d %d",&row[i],&col[i]);
    for(m=1;m<n;m++){
        for(i=0;i<n-m;i++){
            j=i+m,mi=1<<30;
            for(k=i;k<j;k++){
                now=dp[i][k]+dp[k+1][j]+row[i]*col[k]*col[j];
                if(now<mi)mi=now,path[i][j]=k;
            }
            dp[i][j]=mi;
        }
    }
    printf("%d\n",dp[0][n-1]);
    pr(0,n-1);
    return 0;
}
