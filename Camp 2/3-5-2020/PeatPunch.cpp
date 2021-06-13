/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int num,power;
};
stack<A> q;
int a[100100];
int main()
{
    int n,Q,i,num,power;
    scanf("%d %d",&n,&Q);
    for(i=1;i<=n;i++){
        scanf("%d",&num);
        while(!q.empty() && q.top().num>num)q.pop();
        if(q.empty())power=0;
        else{
            power=max(q.top().power,num-q.top().num);
        }
        a[i]=power;
        q.push({num,power});
    }
    sort(a+1,a+n+1);
    while(Q--){
        scanf("%d",&num);
        printf("%d\n",n-(upper_bound(a+1,a+n+1,num)-a-1));
    }
    return 0;
}
/*
5 2
1 3 4 2 3 2 1
*/
