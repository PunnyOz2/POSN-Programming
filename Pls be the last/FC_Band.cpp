/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
#define u first
#define v second
int a[220];
int mark[1010],mark2[1010][1010];
pair<int,int> g[5010];
int main()
{
    int n,m,i,j,ii,jj;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d %d",&g[i].u,&g[i].v);
        mark2[g[i].u][g[i].v]=mark2[g[i].v][g[i].u]=1;
    }
    int cou=0,cou2,ans=0,ans2=0;
    for(i=0;i<m;i++){
        cou=0;
        cou2=0;
        mark[g[i].u]=1;
        mark[g[i].v]=1;
        a[cou++]=g[i].u;
        a[cou++]=g[i].v;
        for(j=i+1;j<m;j++){
            if(mark[g[j].u] || mark[g[j].v])continue;
            cou=2;
            a[cou++]=g[j].u;
            a[cou++]=g[j].v;
            cou2=0;
            for(ii=0;ii<4;ii++){
                for(jj=ii+1;jj<4;jj++){
                    if(mark2[a[ii]][a[jj]]==1)cou2++;
                }
            }
            if(cou2==5)ans++;
            if(cou2==6)ans2++;
        }
        mark[g[i].u]=0;
        mark[g[i].v]=0;
    }
    printf("%d\n",ans/2+ans2/3);
    return 0;
}
/*
4 5
1 2
1 3
1 4
2 3
2 4

6 12
1 2
2 3
3 1
4 1
4 2
4 3
5 1
5 2
5 3
6 1
6 2
6 3
*/
