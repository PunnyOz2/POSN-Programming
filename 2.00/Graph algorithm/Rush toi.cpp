/*
    TASK: Plantation
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int d[310][310];
int main()
{
    int n,i,j,k,m,s,e,w;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            d[i][j]=1<<25;

    while(m--){
        scanf("%d %d %d",&s,&e,&w);
        d[s][e]=min(d[s][e],w);
    }
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
            printf((d[i][j]==1<<25)?"0 ":"%d ",d[i][j]);
            printf("\n");
    }
    return 0;
}
/*
4 5
1 2 10
2 3 10
1 3 15
4 4 10
4 1 10
*/
