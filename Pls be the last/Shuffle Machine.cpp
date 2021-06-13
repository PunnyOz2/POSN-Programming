/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
pair<int,int> opr[10100];
int a[104];
int mark[110];
int cou;
void dfs(int i){
    cou++;
    if(mark[a[a[i]]]!=1)mark[a[i]]=1,dfs(a[i]);
}
int main()
{
    int n,m,i,u,v,ans=1;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)a[i]=i;
    for(i=0;i<m;i++){
        scanf("%d %d",&u,&v);
        swap(a[u],a[v]);
    }
    for(i=1;i<=n;i++){
        if(a[i]!=i && mark[i]!=1){
            cou=0;
            dfs(i);
            ans=(ans*cou)/__gcd(ans,cou);
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
5 2
1 2
1 3
*/
