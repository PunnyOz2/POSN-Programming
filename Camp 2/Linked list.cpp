/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int n,l[500100],r[500100];
void play(int now){
    if(now==n+1)return;
    if(now!=0)printf("%d ",now);
    play(r[now]);
}
int main()
{
    int q,i,a,b;
    char opr;
    scanf("%d %d",&n,&q);
    r[0]=1;
    l[n+1]=n;
    for(i=1;i<=n;i++){
        l[i]=i-1;
        r[i]=i+1;
    }
    while(q--){
        scanf(" %c %d %d",&opr,&a,&b);
        r[l[a]]=r[a];
        l[r[a]]=l[a];
        if(opr=='A'){
            r[l[b]]=a;
            r[a]=b;
            l[a]=l[b];
            l[b]=a;
        }
        else{
            l[a]=b;
            l[r[b]]=a;
            r[a]=r[b];
            r[b]=a;
        }
    }
    play(0);
    return 0;
}
/*
5 1
A 1 4
*/
