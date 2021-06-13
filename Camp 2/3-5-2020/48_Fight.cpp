/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[500100][2],col[100100];
vector<int> g[100100];
int play(int u,int now){
    if(col[u]!=0 && now==col[u])return 1;
    if(col[u]!=0 && now!=col[u])return 0;
    col[u]=now;
    for(auto x:g[u]){
        if(play(x,3-col[u])==0)return 0;
    }
    return 1;
}
int main()
{
    int n,m,i,l,r,mid,ch;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d %d",&a[i][0],&a[i][1]);
    }
    l=1;
    r=m;
    while(l<r){
        mid=(l+r+1)/2;
        ch=0;
        for(i=1;i<=mid;i++){
            g[a[i][0]].push_back(a[i][1]);
            g[a[i][1]].push_back(a[i][0]);
        }
        for(i=1;i<=n;i++){
            if(col[i]==0){
                if(play(i,1)==0){ch=1;break;}
            }
        }
        if(ch==1)r=mid-1;
        else l=mid;
        memset(col,0,sizeof col);
        for(i=1;i<=n;i++){
            g[i].clear();
        }
    }
    printf("%d\n",l+1);
    return 0;
}
