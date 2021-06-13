/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dis[100][100];
int main()
{
    int i,j,k,m,s,e,u,v;
    scanf("%d %d %d",&m,&s,&e);
    for(i=1;i<=60;i++)
        for(j=1;j<=60;j++)
            if(i!=j)
                dis[i][j]=1<<20;
    while(m--){
        scanf("%d %d",&u,&v);
        dis[u][v]=dis[v][u]=1;
    }
    for(k=1;k<=60;k++)
        for(i=1;i<=60;i++)
            for(j=1;j<=60;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            printf("%d\n",dis[s][e]);

    return 0;
}
/*
9 4 30
4 6
4 20
6 7
6 8
7 9
9 10
10 21
21 30
21 25
*/
