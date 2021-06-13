/*
    TASK: Plantation
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int d[1010][1010],x[5010],y[5010],z[5010];
int main()
{
    int q,n,m,i,j,s,e,w,p,k,ch;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                d[i][j]=1<<25;
        for(i=1;i<=n;i++)
            d[i][i]=0;
        while(m--){
            scanf("%d %d %d",&s,&e,&w);
            d[s][e]=d[e][s]=w;
        }
        scanf("%d",&p);
        for(i=0;i<p;i++)
            scanf("%d %d %d",&x[i],&y[i],&z[i]);
        for(k=1;k<=n;k++)
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                    d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
        for(i=1;i<=n;i++){
            for(j=i+1;j<=n;j++){
                for(k=0,ch=1;k<p;k++){
                    s=x[k],e=y[k];
                    if(min(d[s][e],min(d[s][i]+d[j][e],d[s][j]+d[i][e]))!=z[k]){
                        ch=0; break;
                    }
                }
                if(ch){
                    printf("%d %d\n",i,j);
                    goto jump;
                }
            }
        }
        jump: ;
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
4 5
1 2 1
2 3 2
3 4 3
4 1 7
2 4 5
1
2 4 4
*/
