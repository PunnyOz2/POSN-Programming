/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> g[100100];
int mark[100100],color[100100];
int play(int i,int now){
    if(mark[i]==1 && color[i]==now)return 1;
    else if(mark[i]==1 && color[i]!=now)return 0;
    mark[i]=1;
    color[i]=now;
    for(auto x:g[i]){
        if(play(x,3-now)==0)return 0;
    }
    return 1;
}
int main()
{
    int q,n,m,i,u,v,ch;
    scanf("%d",&q);
    while(q--){
        ch=0;
        scanf("%d %d",&n,&m);
        for(i=1;i<=m;i++){
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for(i=1;i<=n;i++){
            if(mark[i]==0){
                if(play(i,1)==0)ch=1;
            }
        }
        if(ch==1)printf("no\n");
        else printf("yes\n");
        for(i=1;i<=n;i++){
            g[i].clear();
        }
        memset(mark,0,sizeof mark);
        memset(color,0,sizeof color);
    }
    return 0;
}
