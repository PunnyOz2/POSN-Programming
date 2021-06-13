/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int c[200100],mark[200100],dis[200100],n;
void dfs(int u){
    int x=c[u];
    if(x>n)return;
    if(mark[x]==0){
        mark[x]=mark[u];
        dis[x]=dis[u]+1;
        dfs(x);
    }
}
int main()
{
    int q,cou,i,u,v,a,b,temp,templ,tempr;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++)scanf("%d",&c[i]);
    cou=1;
    for(i=1;i<=n;i++){
        if(mark[i]==0){
            mark[i]=cou++;
            dis[i]=1;
            dfs(i);
        }
    }
    while(q--){
        scanf("%d %d %d %d",&u,&v,&a,&b);
        temp=0;
        if(a==b){
            if(mark[u]==mark[v]){
                printf("DEAD\n");continue;
            }
            else {printf("SURVIVE\n");continue;}
        }
        else if(mark[a]!=mark[b]){
            if(mark[u]==mark[v]){
                printf("DEAD\n");continue;
            }
            if(mark[u]==mark[a] || mark[u]==mark[b])temp++;
            if(mark[v]==mark[a] || mark[v]==mark[b])temp++;
            if(temp==2){printf("DEAD\n");continue;}
            else {printf("SURVIVE\n");continue;}
        }
        else if(mark[a]==mark[b]){
            if(mark[u]!=mark[a] && mark[u]==mark[v]){
                printf("DEAD\n");continue;
            }
            if(mark[u]!=mark[a] && mark[u]!=mark[v]){
                printf("SURVIVE\n");continue;
            }
            templ=min(dis[a],dis[b]);
            tempr=max(dis[a],dis[b]);
            if(dis[u]>templ && dis[u]<=tempr && dis[v]>templ && dis[v]<=tempr){printf("DEAD\n");continue;}
            else if(!(dis[u]>templ && dis[u]<=tempr) && !(dis[v]>templ && dis[v]<=tempr)){printf("DEAD\n");continue;}
            else {printf("SURVIVE\n");continue;}
        }
    }
    return 0;
}
/*
5 10
1 5 4 2 3
3 5 4 5
*/
