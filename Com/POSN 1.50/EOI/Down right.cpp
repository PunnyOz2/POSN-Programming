/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int b[260][260];
int n,m,sumold=-10000000;
void play(int i,int j,int state,int sum){
    if(i>=n||j>=m) return;
    if(state==(n+m-2)){
        sum+=b[i][j];
        if(sum>sumold) sumold=sum;
        return;
    }
    sum+=b[i][j];
    play(i+1,j,state+1,sum);
    play(i,j+1,state+1,sum);
}
int main()
{
    int i,j;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)
            scanf("%d",&b[i][j]);
    }
    play(0,0,0,0);
    printf("%d",sumold);
    return 0;
}
/*
3 3
5 19 47
75 3 1
4 5 24
*/
