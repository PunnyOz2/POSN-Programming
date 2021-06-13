/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int p[300100];
int mark[300100];
int t[300100];
int fin(int i){
    if(p[i]==i)return i;
    return p[i]=fin(p[i]);
}
int main()
{
    int n,m,ch,pu,pv,i,u,v;
    scanf("%d %d",&m,&n);
    for(i=1;i<=n;i++)   p[i]=t[i]=i;
    while(m--){
        ch=0;
        scanf("%d %d",&u,&v);
        pu=fin(u),pv=fin(v);
        if(!mark[u]){
            mark[u]=1;
            p[pv]=pu;
            t[pu]=t[pv];
            ch=1;
        }
        else if(!mark[v])
        {
            mark[v]=1;
            p[pu]=pv;
            t[pv]=t[pu];
            ch=1;
        }
        else if(!mark[t[pu]])
        {
            mark[t[pu]]=1;
            p[pv]=pu;
            t[pu]=t[pv];
            ch=1;
        }
        else if(!mark[t[pv]])
        {
            mark[t[pv]]=1;
            p[pu]=pv;
            t[pv]=t[pu];
            ch=1;
        }
        if(ch==1)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
/*
5 3
1 2
1 3
1 2
1 2
1 3
*/
