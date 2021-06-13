/*
    TASK: Fairy_Land
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
map<string, int>mp;
vector<int> g[50];
char a[10],b[10];
queue<int> bfs;
int mark[50];
int main()
{
    int n,m,p,i,st,en,now,ch,k;
    scanf("%d %d %d",&n,&m,&p);
    for(i=1;i<=n;i++){
        scanf(" %s",a);
        mp[ a ]= i;
    }
    while(m--){
        scanf(" %s %s",a,b);
        g[ mp[a]].push_back(mp[b]);
        g[ mp[b]].push_back(mp[a]);
    }
    while(p--){
        scanf("%d %s %s",&i,a,b);
        st =mp[a], en = mp[b], ch=0;
        memset(mark,-1,sizeof mark);
        mark[st]=0;
        bfs.push(st);
        while(!bfs.empty()){
            now = bfs.front(); bfs.pop();
            if(now==en){
                ch=1; break;
            }
            for(k=0;k<g[now].size();k++){
                if(mark[g[now][k]]==-1)
                    mark[g[now][k]]=mark[now]+1,bfs.push(g[now][k]);
            }
        }
        if(ch) printf("%s %s %d\n",a,b,mark[en]*i*1128);
        else printf("NO SHIPMENT POSSIBLE");
        while(!bfs.empty())
            bfs.pop();
    }

    return 0;
}
/*

*/
