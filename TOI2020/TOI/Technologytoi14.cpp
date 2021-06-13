#include <bits/stdc++.h>
using namespace std;
int mark[100100],now[100100],tim;
vector<int> g[100100],coutech[100100];
queue<int> q;
void play(int u){
    if(now[u]==1){tim=1<<30;return;}
    if(mark[u]==1) return;
    now[u]=1;
    mark[u]=1;
    tim++;
    for(auto x:g[u]) play(x);
    now[u]=0;
}
int main(){
    int n,k,t,tt,i,cc,j,u;
    scanf("%d %d %d",&n,&k,&t);
    for(i=1;i<=n;i++){
        scanf("%d %d",&tt,&cc);
        coutech[tt].push_back(i);
        for(j=1;j<=cc;j++){
            scanf("%d",&u);
            g[i].push_back(u);
        }
    }
    for(i=1;i<=k;i++){
        for(auto x:coutech[i]) play(x);
        if(tim>t){
            if(i==1)printf("-1\n");
            else printf("%d",i-1);
            break;
        }
    }
}
/*
6 5 4
1 0
5 1 1
2 1 2
4 2 3 5
3 1 6
2 1 1
*/
