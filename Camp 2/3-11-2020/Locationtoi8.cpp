/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010][1010];
int main()
{
    int n,m,k,i,j;
    scanf("%d %d",&n,&m);
    scanf("%d",&k);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            a[i][j]+=a[i][j-1]+a[i-1][j]-a[i-1][j-1];
        }
    }
    int Max=0;
    for(i=k;i<=n;i++){
        for(j=k;j<=m;j++){
            Max=max(Max, a[i][j] - a[i-k][j] - a[i][j-k] + a[i-k][j-k]);
        }
    }
    printf("%d\n",Max);
    return 0;
}
/*

*/
