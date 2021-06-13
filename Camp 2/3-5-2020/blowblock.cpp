/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
priority_queue<long long> q[3][3];
int main()
{
    long long n,i,j,num,sum=0;
    scanf("%lld",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%lld",&num);
            q[i%2][j%2].push(num);
        }
    }
    while(!q[0][0].empty() && !q[0][1].empty() && !q[1][0].empty() && !q[1][1].empty()){
        sum+=q[0][0].top()*q[0][1].top()*q[1][0].top()*q[1][1].top();
        q[0][0].pop();q[0][1].pop();q[1][0].pop();q[1][1].pop();
    }
    printf("%lld\n",sum);
    return 0;
}
/*
4
1 1 2 1
1 1 1 1
1 1 1 1
1 3 1 1
*/
