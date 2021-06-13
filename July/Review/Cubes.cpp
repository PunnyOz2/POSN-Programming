/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[200100],last[100100];
vector<int> g[100100];
int main()
{
    int n,m,k,ans=0,i,num,l,r;
    scanf("%d %d %d",&n,&m,&k);
    for(i=1;i<=n;i++){
        scanf("%d",&num);
        g[num].push_back({i});
    }
    for(i=1;i<=m;i++){
        l=0,r=0;
        while(r!=g[i].size()){
            if(g[i][r]-g[i][l]+1-(r-l+1)<=k)ans=max(ans,r-l+1),r++;
            else l++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
10 3 2
1 2 1 1 3 2 1 1 2 2
*/
