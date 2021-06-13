/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int totalplayed=0;
int co[5000000],n;
void play(int now){
    if(now!=1 && co[now/2]==1){
        if(co[now/2*2]==0 && co[now/2*2+1]==1)co[now/2*2]=1,totalplayed++,play(now/2*2);
        if(co[now/2*2]==1 && co[now/2*2+1]==0)co[now/2*2+1]=1,totalplayed++,play(now/2*2+1);
    }
    if(now!=1 && co[now/2*2+1]==1 && co[now/2*2]==1 && co[now/2]==0)co[now/2]=1,totalplayed++,play(now/2);
    if(now<(1<<(n+1))){
        if(co[now*2]==1 && co[now*2+1]==0)co[now*2+1]=1,totalplayed++,play(now*2+1);
        if(co[now*2]==0 && co[now*2+1]==1)co[now*2]=1,totalplayed++,play(now*2);
    }
}
int main()
{
    int m,i,a,b,ans=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++){
        //printf("hi\n");
        scanf("%d %d",&a,&b);
        //printf("%d\n",(1<<(n-a))+(b/(1<<(a))));
        if(co[(1<<(n-a))+(b/(1<<(a)))]==0){
            totalplayed++,co[(1<<(n-a))+(b/(1<<(a)))]=1;
            play((1<<(n-a))+(b/(1<<(a))));
        }
        //printf("%d\n",totalplayed);
        if(ans==0 && totalplayed==((1<<(n+1))-1))ans=i;
    }
    printf("%d\n",ans);
    return 0;
}
/*
2 7
2 0
0 1
0 0
1 0
0 3

0 2
1 2
*/
