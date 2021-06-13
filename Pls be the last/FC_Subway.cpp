/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int d[550][550];
vector<int> g[1000100];
int main()
{
    int n,m,i,nn,j,k,a,b,Min,num,q;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d",&nn);
        for(j=0;j<nn;j++){
            scanf("%d",&num);
            g[num].push_back(i);
        }
    }
    for(i=1;i<=m;i++){
        for(j=1;j<=m;j++){
            if(i==j)continue;
            d[i][j]=1<<29;
        }
    }
    for(i=1;i<=n;i++){
        for(j=0;j<g[i].size();j++){
            for(k=j+1;k<g[i].size();k++){
                if(g[i][j]!=g[i][k])
                    d[g[i][j]][g[i][k]]=d[g[i][k]][g[i][j]]=1;
            }
        }
    }
    for(k=1;k<=m;k++){
        for(i=1;i<=m;i++){
            for(j=1;j<=m;j++){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    scanf("%d",&q);
    while(q--){
        Min=1<<29;
        scanf("%d %d",&a,&b);
        for(i=0;i<g[a].size();i++){
            for(j=0;j<g[b].size();j++){
                Min=min(Min,d[g[a][i]][g[b][j]]);
            }
        }
        if(Min==1<<29)printf("impossible\n");
        else printf("%d\n",Min);
    }
    return 0;
}
/*
6 2
3 1 2 3
3 2 4 5
3
1 3
1 4
2 6

15 5
6 1 2 3 4 2 5
2 6 7
4 1 6 8 9
4 10 11 12 13
3 14 11 15
6
9 2
10 13
10 5
3 7
6 14
15 12
*/
