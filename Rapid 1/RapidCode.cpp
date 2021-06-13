/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dis[310][310];
int main()
{
	int n,m,j,k,i,u,v,w;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(i!=j)dis[i][j]=1<<20;
    for(i=0;i<m;i++){
        scanf("%d %d %d",&u,&v,&w);
        dis[u][v]=min(dis[u][v],w);
    }
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(dis[i][j]!=1<<20)
                printf("%d ",dis[i][j]);
            else printf("-1 ");
        }
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
