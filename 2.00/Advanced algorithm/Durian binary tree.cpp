/*
    TASK: Durian
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v[110];
int p[110];
int mic[110][110];
vector<int> child[110];
void Dfs(int now){
    for(auto x:v[now]){
        if(p[x.first]==-1){
            p[x.first]=x.second;
            child[now].push_back(x.first);
            Dfs(x.first);
        }
    }
}
int Play(int now,int k){
    if(mic[now][k]!=-1) return mic[now][k];
    if(k==0)return 0;
    if(child[now].size()==0) return p[now];
    if(child[now].size()==1)
        return mic[now][k]= Play(child[now][0],k-1)+p[now];
    int Max=-1;
    for(int i=0;i<=k-1;i++){
        Max = max(Max,Play(child[now][0],i)+Play(child[now][1],k-i-1)+p[now]);
    }
    return mic[now][k]=Max;
}
int main()
{
    int n,k,s,e,val,i;
    scanf("%d %d",&n,&k);
    memset(p,-1,sizeof p);
    memset(mic,-1,sizeof mic);
    for(i=1;i<n;i++){
        scanf("%d %d %d",&s,&e,&val);
        v[s].push_back({e,val});
        v[e].push_back({s,val});
    }
    p[1]=0;
    Dfs(1);
    printf("%d",Play(1,k+1));
    return 0;
}
/*
5 2
1 3 1
1 4 10
2 3 20
3 5 20
*/
