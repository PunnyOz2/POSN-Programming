/*
    TASK: Plantation
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
#define INF 2000000000
using namespace std;
struct A{
    int u,v,w;
};
A a[1111];
int dis[2000],temp[2000],s;
int main()
{
    int n,m,k,t,cnt=0,i,j;
    scanf("%d %d %d %d",&n,&m,&k,&t);
    for(i=0;i<m;i++)
        scanf("%d %d %d",&a[cnt].u,&a[cnt].v,&a[cnt].w),cnt++;
    for(i=0;i<k;i++)
        scanf("%d %d %d",&a[cnt].u,&a[cnt].v,&a[cnt].w),a[cnt].w*=-1,cnt++;
    while(t--){
        scanf("%d",&s);
        for(i=1;i<=n;i++)
            dis[i]=INF;
        dis[s]=0;
        for(i=0;i<n-1;i++)
            for(j=0;j<cnt;j++)
                if(dis[a[j].u]!=INF && dis[a[j].u]+a[j].w<dis[a[j].v])
                    dis[a[j].v] = dis[a[j].u]+a[j].w;
        for(i=1;i<=n;i++)
            temp[i]=dis[i];
        for(j=0;j<cnt;j++)
            if(dis[a[i].u]!=INF && dis[a[j].u]+a[j].w<dis[a[j].v])
                dis[a[j].v]=dis[a[j].u]+a[j].w;
        for(i=1;i<=n;i++){
            if(dis[i]!=temp[i]||dis[i]==INF)
                printf("-1 ");
            else printf("%d ",dis[i]);
        }
        printf("\n");
    }
    return 0;
}
/*
10 5 5 5
1 7 8
2 5 1
3 4 7
5 8 4
5 1 11
10 1 6
10 5  3
10 3 1
9 5 10
5 7 2
2
4
6
8
10
*/
