/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int mark[310][310];
int mem[310][310];
int play(int l,int r){
    int Max=-1;
    if(l==r)return mark[l][r];
    if(mem[l][r]!=-1)return mem[l][r];
    for(int k=l;k<r;k++){
        Max=max(Max,play(l,k)+play(k+1,r));
    }
    return mem[l][r]=Max+mark[l][r];
}
int main()
{
    int n,m,i,u,v;
    memset(mem,-1,sizeof mem);
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d %d",&u,&v);
        mark[u][v]++;
    }
    printf("%d\n",m-play(1,n));

    return 0;
}
/*
10
6
1 5
4 10
1 3
4 5
4 5
3 7
*/
