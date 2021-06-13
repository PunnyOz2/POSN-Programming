/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long a[5010];
priority_queue<long long> q;
int main()
{
    long long n,m,i,sum,ans=0;
    scanf("%lld %lld",&n,&m);
    sum=0;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){

        }
    }
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(a[i]>=0)sum+=a[i];
        if(a[i]<0 || i==n)q.push(sum),printf("%d\n",sum),sum=0;
    }
    while(!q.empty() && m--){
        ans+=q.top();
        q.pop();
    }
    printf("%lld\n",ans);
    return 0;
}
/*
20 3
1 2 3 2 1 -100 7 0 -5 8 7 4 2 -9 7 5 -4 98 -4 5 2

11 2
1 2 3 4 -5 6 -1 -2 -3 8 9
*/
