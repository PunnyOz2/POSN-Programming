/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int p[25],cou=0,n,arr[25];
vector<int> g[24];
void permutation(int now,int last){
    if(now>n+1)return;
    int i;
    for(i=1;i<now;i++){
        for(auto x:g[p[i]]){
            if(arr[x]!=0)return;
        }
        arr[p[i]]=1;
    }
    for(i=last+1;i<=n;i++){
        p[now]=i;
        permutation(now+1,i);
    }
    cou++;
    return;
}
int main()
{
    int m,u,v,i;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    permutation(1,0);
    printf("%d\n",cou);
    return 0;
}
/*
3 2
1 2
2 3
*/
