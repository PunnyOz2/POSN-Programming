/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j;
};
A a[750];
int col[750];
vector<int> g[750];
int play(int u,int now){
    if(col[u]!=0 && now==col[u])return 1;
    if(col[u]!=0 && now!=col[u])return 0;
    col[u]=now;
    for(auto x : g[u]){
        if(play(x,3-col[u])==0)return 0;
    }
    return 1;
}
int main()
{
    int q,n,i,cou,j,ans;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d %d",&a[i].i,&a[i].j);
        }
        cou=0;
        for(i=1;i<n;i++){
            for(j=i+1;j<=n;j++){
                if( (a[i].i<a[j].i && a[j].j<a[i].j ) || (a[j].i<a[i].i && a[i].j<a[j].j)){continue;}
                else if( a[j].i<a[i].j && a[i].j<a[j].j && a[i].i<a[j].i)g[i].push_back(j),g[j].push_back(i);
                else if( a[i].i<a[j].j && a[j].j<a[i].j && a[j].i<a[i].i)g[i].push_back(j),g[j].push_back(i);
            }
        }
        for(i=1;i<=n;i++){
            if(col[i]==0){
                cou++;
                if(play(i,1)==0){printf("0\n");goto jump;}
            }
        }
        ans=1;
        for(i=1;i<=cou;i++){
            ans*=2;
            ans%=1001;
        }
        printf("%d\n",ans);
        jump:;
        memset(col,0,sizeof col);
        for(i=1;i<=n;i++){
            g[i].clear();
        }
    }
    return 0;
}
