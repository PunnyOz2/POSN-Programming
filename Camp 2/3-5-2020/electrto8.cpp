/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int pos,cost;
};
deque<A> q;
int a[500100];
int main()
{
    int n,k,i,cost;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    q.push_back({1,a[1]});
    for(i=2;i<=n;i++){
        while(!q.empty() && q.front().pos<i-k)q.pop_front();
        cost=a[i];
        if(!q.empty())cost+=q.front().cost;
        //printf("%d %d\n",i,cost);
        while(!q.empty() && q.back().cost>=cost)q.pop_back();
        q.push_back({i,cost});
    }
    printf("%d\n",q.back().cost);
    return 0;
}
/*
10
4
2 1 4 3 2 1 5 1 2 3
*/
