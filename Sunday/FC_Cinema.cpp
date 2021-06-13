/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<long long,long long>> q;
vector<long long> g;
int main()
{
    long long n,m,sum=0,i,a,b;
    scanf("%lld %lld",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%lld %lld",&a,&b);
        if(a>=b)sum+=b,q.push({0,-i});
        else sum+=a,q.push({min(a*2-a,b-a),-i});
    }
    while(!q.empty()&& m--){
        sum+=q.top().first;
        g.push_back(-1*q.top().second);
        q.pop();
    }
    sort(g.begin(),g.end());
    for(auto x:g){
        printf("%lld ",x);
    }
    printf("\n");
    printf("%lld\n",sum);
    return 0;
}
/*
4 2
2 1
3 5
2 3
1 5
*/
