/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int MA[1005],val[1000007];
int sq=1000;
    int n,m,a,b;
int block(int i){
    return i/sq+1;
}
int leftmost(int i){
    return (i-1)*sq;
}
int rightmost(int i){
    return (i-1)*sq+sq+1;
}
int getleft(int pos,int V){
    int i,j;
    for(i=pos;i>=leftmost(block(i));i--){
        if(V<val[i])return pos-i;
    }
    for(i=block(i)-1;i>0;i--){
        if(MA[i]<=V)continue;
        for(j=leftmost(i);V>=val[j];j--);
        return pos-j;
    }
    return 1<<30;
}
int getright(int pos,int V){
    int i,j;
    for(i=pos;i<=rightmost(block(pos));i++){
        if(V<val[i])return i-pos;
    }
    for(i=block(pos)+1;i<=block(n);i++){
        if(MA[i]<=V)continue;
        for(j=leftmost(i);val[j]<=V;j++);
        return j-pos;
    }
    return 1<<30;
}
int main()
{
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d",&a,&b);
        int ans=min(n,min(getleft(a,b),getright(a,b)));
        printf("%d\n",ans);
        MA[block(a)]=max(MA[block(a)],b);
        val[a]=b;
    }
    return 0;
}
