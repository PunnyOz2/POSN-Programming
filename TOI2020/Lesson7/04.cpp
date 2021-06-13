#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> same;
int color[50100];
vector<int> g[50100],g2[50100];
int group;
int gr[50100];
int col(int u,int state){
    color[u]=state;
    gr[u]=group;
    //printf("%d %d %d %d\n",u,state,g[u].size(),g2[u].size());
    for(auto x:g[u]){
        //printf(" %d\n",x);
        if(color[x]==color[u])return 1;
        if(color[x]==0){
            if(col(x,state%3+1)==1) return 1;
        }
    }
    for(auto x:g2[u]){
        //printf("  %d\n",x);
        if(color[x]==color[u])return 1;
        if(color[x]==0){
            if(col(x,state%3+1)==1) return 1;
        }
    }
    return 0;
}
int main(){
    int q,n,m,u,v,cou=0,opr,i,ch;
    scanf("%d",&q);
    while(q--){
        cou=0;
        scanf("%d %d",&n,&m);
        while(m--){
            scanf("%d %d %d",&opr,&u,&v);
            ch=0;
            if(u>n || v>n){
                cou++;
                continue;
            }
            if(opr==2){
                if(u==v)ch=1,cou++;
                else{
                    group=0;
                    g[u].push_back(v);
                    g2[v].push_back(u);
                    for(i=1;i<=n;i++){
                        if(color[i]==0){
                            group++;
                            if(col(i,1)==1){
                                ch=1;break;
                            }
                        }
                    }
                    for(auto x:same){
                        if(gr[x.first]==gr[x.second]){
                            if(color[x.first]!=color[x.second]){ch=1;break;}
                        }
                    }
                    if(ch==1)cou++,g[u].pop_back(),g2[v].pop_back();
                }
                memset(color,0,sizeof color);
                memset(gr,0,sizeof gr);
            }
            if(opr==1){
                group=1;
                col(u,1);
                group=2;
                if(color[v]==0)col(v,1);
                if(gr[u]==gr[v]){
                    if(color[u]!=color[v])ch=1;
                }
                if(ch==1)cou++;
                else same.push_back({u,v});
                memset(color,0,sizeof color);
                memset(gr,0,sizeof gr);
            }
        }
        printf("%d\n",cou);
        for(i=1;i<=n;i++)g[i].clear();
        same.clear();
    }
    return 0;
}
/*
1
100 7
1 101 1
2 1 2
2 2 3
2 3 3
1 1 3
2 3 1
1 5 5

*/
