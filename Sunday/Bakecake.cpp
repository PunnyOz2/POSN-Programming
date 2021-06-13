/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
priority_queue<int> q;
int num,i,Q,opr;
int main()
{
    int n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&num);
        cou[num]++;
    }
    scanf("%d",&Q);
    while(Q--){
        scanf("%d %d",&opr,&num);
        if(opr==2)printf("%d\n",mp[num]);
        else if(opr==1){
            while(!q.empty() && q.top()){

            }
        }
    }
    return 0;
}
/*
5 10 5 7 5 4
7 2 5 1 6 2 1 2 4 1 4 2 1 2 0
*/
