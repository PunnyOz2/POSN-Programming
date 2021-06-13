/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int n,m,S,T;
int F[105][105],p[105],mk[105];
queue<int> bfs;
bool shortestpath(){
    int i;
    memset(mk,-1,sizeof mk);
    mk[S]=0;
    bfs.push(S);
    while(!bfs.empty()){
        int now=bfs.front();
        bfs.pop();
        for(i=1;i<=n;i++){
            if(F[now][i]!=0 &&mk[i]==-1){
                mk[i]=mk[now]+1;
                p[i]=now;
                bfs.push(i);
            }
        }
    }
    return mk[T]!=-1;
}
int push_flow(int now,int flow){
    if(now==S)return flow;
    flow=push_flow(p[now],min(flow,F[p[now]][now]));
    F[p[now]][now]-=flow;
    F[now][p[now]]+=flow;
    return flow;
}
int main()
{
    int i,j,k,l,a,b,c,d,ans=0;
    scanf("%d %d %d %d",&n,&m,&S,&T);
    for(i=0;i<m;i++){
        scanf("%d %d %d",&a,&b,&c);
        F[a][b]=c;
    }
    while(shortestpath()){
        ans+=push_flow(T,1<<30);
    }
    printf("%d\n",ans);
    return 0;
}
