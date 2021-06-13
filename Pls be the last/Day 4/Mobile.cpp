/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int cou=0;
int l[100100],r[100100];
pair<int,int> dfs(int u,int lev){
    if(u==-1)return {lev,lev};
    pair<int,int> ll=dfs(l[u],lev+1);
    pair<int,int> rr=dfs(r[u],lev+1);
    if(ll.second-rr.first>=0 && ll.second-rr.first<=1)return {ll.first,rr.second};
    if(rr.second-ll.first>=0 && rr.second-ll.first<=1){cou++;return {rr.first,ll.second};}
    printf("-1\n");exit(0);
}
int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d %d",&l[i],&r[i]);
    }
    pair<int,int> ll = dfs(1,1);
    if(ll.first-ll.second>1)
    {
        printf("-1\n");
    }
    else printf("%d\n",cou);
    return 0;
}
