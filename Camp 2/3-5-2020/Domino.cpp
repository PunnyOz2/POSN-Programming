/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int pos,cou;
};
stack<A> q;
int R[100100],L[100100];
int pos[100100],h[100100];
int main()
{
    int n,Max=0,i,cou,now;
    char op;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d %d",&pos[i],&h[i]);
    }
    for(i=1;i<=n;i++){
        cou=1;
        while(!q.empty() && q.top().pos>pos[i]-h[i]){
            cou+=q.top().cou;
            q.pop();
        }
        L[i]=cou;
        q.push({pos[i],cou});
    }
    while(!q.empty())q.pop();
    for(i=n;i>=1;i--){
        cou=1;
        //printf("%d\n",i);
//        if(!q.empty()){
//            printf(" %d\n",q.top().pos);
//        }
        //printf("  %d ",pos[i]+h[i]);
        while(!q.empty() && q.top().pos<pos[i]+h[i]){
            cou+=q.top().cou;
            q.pop();
        }
        R[i]=cou;
        //printf("%d\n",cou);
        q.push({pos[i],cou});
    }
    int idx;
    for(i=1;i<=n;i++){
        if(Max<L[i]){
            Max=L[i];
            op='L';
            idx=i;
        }
        if(Max<R[i]){
            Max=R[i];
            op='R';
            idx=i;
        }
        //printf("%d %d %d\n",n,L[i],R[i]);
    }
    printf("%d %c",idx,op);
    return 0;
}
/*
5
1 1
3 3
5 4
7 15
10 3

2 R

5
1 2
2 2
4 2
6 2
8 2
*/
