/*
    TASK: Plantation
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int d[600][600];
int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&d[i][j]);
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                d[i][j]|=(d[i][k]&d[k][j]);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
            printf("%d ",d[i][j]);
        printf("\n");
    }

    return 0;
}
/*
4
0 0 1 0
1 0 0 1
0 0 0 0
0 1 0 0
*/
