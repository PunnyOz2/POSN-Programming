/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int k,c[110];
void play(int w,int l,int state){
    if(w==k||l==k){
        for(int i=0;i<state;i++)
            printf((c[i]==1)?"W ":"L ");
        printf("\n");
        return;
    }
    c[state]=1;
    play(w+1,l,state+1);
    c[state]=2;
    play(w,l+1,state+1);
}
int main()
{
    int a,b;
    scanf("%d %d %d",&k,&a,&b);
    play(a,b,0);
    return 0;
}
