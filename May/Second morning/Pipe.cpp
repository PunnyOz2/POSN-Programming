/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dis[15005];
pair<int,int> pos[15005];
int main()
{
    int n,m,i,j,u,v,ans,ii,Min,idx;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d %d",&pos[i].first,&pos[i].second),dis[i]=1<<30;
    for(i=1;i<n;i++){
        Min=1<<30;
        for(j=i+1;j<=n;j++){
            dis[j]=min(dis[j],abs(pos[i].first-pos[j].first)+abs(pos[i].second-pos[j].second));
            if(dis[j]<Min)Min=dis[j],idx=j;
        }
        swap(pos[i+1],pos[idx]);
        swap(dis[i+1],dis[idx]);
    }
    sort(dis+2,dis+1+n);
    int sum=0;
    //for(i=0;i<=n;i++)printf("%d ",dis[i]);
    for(i=2;i<2+n-m;i++){
        sum+=dis[i];
    }
    printf("%d\n",sum);
    return 0;
}
/*
5 2
2 9
9 7
14 2
12 9
16 4

*/
