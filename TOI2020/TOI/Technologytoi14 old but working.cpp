#include <bits/stdc++.h>
using namespace std;
int coutech[10100],tech[100100],in[100100],Min[100100],ans[10100];
vector<int> g[100100];
void play(int u){
    Min[u]=tech[u];
    for(int i=0;i<g[u].size();i++){
        if(!Min[g[u][i]])play(g[u][i]);
        Min[u]=min(Min[u],Min[g[u][i]]);
    }
}
struct A{
    int u,Min;
    bool operator<(const A&o)const{
        return Min>o.Min;
    }
};
priority_queue<A> h;
int main(){
    int n,k,t,tt,i,cc,j,u,mi,far;
    scanf("%d %d %d",&n,&k,&t);
    for(i=1;i<=n;i++){
        scanf("%d %d",&tt,&cc);
        tech[i]=tt;
        coutech[tt]++;
        for(j=1;j<=cc;j++){
            scanf("%d",&u);
            g[u].push_back(i);
            in[i]++;
        }
    }
    for(i=1;i<=n;i++){
      if(!Min[i])play(i);
    }
    for(i=1;i<=n;i++){
        if(in[i]==0){
            h.push({i,Min[i]});
        }
    }
    while(!h.empty() && t--){
        u=h.top().u;
        mi=h.top().Min;
        h.pop();
        ans[tech[u]]++;
        for(int i=0;i<g[u].size();i++){
            in[g[u][i]]--;
            if(in[g[u][i]]==0){
                h.push({g[u][i],Min[g[u][i]]});
            }
        }
    }
    for(i=1;i<=k;i++){
        if(coutech[i]!=ans[i]){
            if(i==1)printf("-1\n");
            else printf("%d\n",i-1);
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
