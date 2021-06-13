/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int cou[15][15],path[15][15];
struct A{
    int i,j;
};
A a[100];
void prin(int l,int r){
    if(l==r){printf("A%d",l);return;}
    printf("(");
    prin(l,path[l][r]);
    printf(" x ");
    prin(path[l][r]+1,r);
    printf(")");
}
int play(int l,int r){
    if(l==r)return 0;
    int Min=1<<30,MT;
    int temp,temp2;
    int i,ti,tj,cc,cc2;
    for(i=l;i<r;i++){
        temp=play(l,i);
        temp2=play(i+1,r);
        MT=a[l].i*a[i].j*a[r].j;
        if(MT+temp+temp2<Min){
            Min=MT+temp+temp2;
            path[l][r]=i;
        }
    }
    //printf("%d %d %d\n",l,r,Min);
    return Min;
}
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d %d",&a[i].i,&a[i].j);

    printf("%d\n",play(1,n));
    prin(1,n);
    return 0;
}
/*
3
5 10
10 20
20 35
*/
