/*
    TASK: Ant
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int A[500010],start=0,kwa=1,N,M;
int fin(int l){
    if(kwa) return(start+l-1)%N;
    else return(start-l+1+N)%N;
}
int main()
{
    int i,val,b,c,l,j,k;
    char com;
    scanf("%d %d",&N,&M);
    for(i=0;i<=N;i++){
        scanf("%d",&A[i]);
    }
    while(M--){
        scanf(" %c",&com);
        if(com=='a'){
            scanf("%d %d",&b,&c);
            j=fin(b),k=fin(c);
            swap(A[j],A[k]);
        }
        else if(com=='b'){
            scanf("%d %d",&b,&c);
            A[fin(b)] = c;
        }
        else if(com=='c'){
            scanf("%d",&b);
            start=fin(b);
            kwa^=1;
        }
        else if(com=='q'){
            scanf("%d",&b);
            printf("%d\n",A[fin(b)]);
        }
    }
    return 0;
}
/*
5 6
1 3 4 5 2
q 3
b 3 6
a 2 4
q 2
c 1
q 4
*/
