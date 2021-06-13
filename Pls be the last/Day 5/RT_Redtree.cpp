/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int mark[100100],p[100100];
int fin(int i){
    if(p[i]==i)return i;
    return fin(p[i]);
}
int cou;
void fin2(int i){
    if(mark[i]==1)return;
    cou++;
    fin2(p[i]);
    return;
}
int main()
{
    int n,m,i,j,opr,u,v,pu,pv;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)p[i]=i;
    for(i=0;i<n-1;i++){
        scanf("%d %d",&u,&v);
        if(u!=v){
            if(u>v)swap(u,v);
            p[v]=u;
        }
    }
    mark[1]=1;
    while(m--){
        scanf("%d %d",&opr,&u);
        if(opr==1)mark[u]=1;
        else{
            cou=0;
            fin2(u);
            printf("%d\n",cou);
        }
    }
    return 0;
}
/*
5 4
1 2
2 3
2 4
4 5
2 1
2 5
1 2
2 5
*/
