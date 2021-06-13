/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dis[250][250],x[6000],y[6000],z[6000];
int main()
{
	int Q,p,n,m,i,j,w,u,v,k,e,ch,s;
	scanf("%d",&Q);
	while(Q--){
        ch=1;
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(i!=j)dis[i][j]=1<<25;
        for(i=0;i<m;i++){
            scanf("%d %d %d",&u,&v,&w);
            dis[u][v]=w;
            dis[v][u]=w;
        }
        for(k=1;k<=n;k++){
            for(i=1;i<=n;i++){
                for(j=1;j<=n;j++){
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }
        scanf("%d",&p);
        for(i=0;i<p;i++)
            scanf("%d %d %d",&x[i],&y[i],&z[i]);

        for(i=1;i<=n;i++){
            for(j=i+1;j<=n;j++){
                for(k=0,ch=1;k<p;k++){
                    s=x[k],e=y[k];
                    if(min(dis[s][e],min(dis[s][i]+dis[j][e],dis[s][j]+dis[i][e]))!=z[k]){
                        ch=0;break;
                    }
                }
                if(ch){
                    printf("%d %d\n",i,j);
                    goto jump;
                }
            }
        }
        jump:;
	}
    return 0;
}
/*
2
5 5
1 2 3
2 3 6
2 5 4
3 4 2
3 5 6
2
4 5 7
1 5 7
*/
