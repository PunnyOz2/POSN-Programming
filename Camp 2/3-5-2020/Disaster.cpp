/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int mark[40][40],n,ans[1000],i,cou[40];
vector<int>g[30];
void play(int u,int now){
    ans[now]=u;
    if(now==n){
        for(i=0;i<=n;i++){
            printf("%c ",ans[i]+'A');
        }
        exit(0);
    }
    for(auto x:g[u]){
        if(mark[u][x]==0){
            mark[u][x]=mark[x][u]=1;
            play(x,now+1);
            mark[u][x]=mark[x][u]=0;
        }
    }
}
int main()
{
    int Min,st=-1;
    char a,b;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf(" %c %c",&a,&b);
        g[a-'A'].push_back(b-'A');
        g[b-'A'].push_back(a-'A');
        cou[a-'A']++;
        cou[b-'A']++;
    }
    Min=100;
    for(i=0;i<26;i++){
        sort(g[i].begin(),g[i].end());
    }
    for(i=0;i<26;i++){
        if(g[i].size()%2==1){st=i;break;}
        if(cou[i]>0)Min=min(Min,i);
    }
    if(st==-1){
        st=Min;
    }
    play(st,0);
    return 0;
}
/*
6
AB
AE
BD
BC
CE
DE
*/
