/*
    TASK: BUU contest
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
priority_queue<long long> h;
int main()
{
    long long d,k,n,b,sum=0,ans=0,num;
    scanf("%lld %lld",&d,&k);
    while(d--){
        scanf("%lld %lld",&n,&b);
        while(n--){
            scanf("%lld",&num);
            h.push(num-sum);
        }
        while(b--){
            ans+= h.top()+sum;
            h.pop();
        }
	sum +=k;
    }
    printf("%lld\n",ans);
    return 0;
}
/*
3 10
5 2
8 4 5 1 10
4 3
14 4 9 14
2 1
20 7
*/
