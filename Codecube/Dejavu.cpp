/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100100];
vector<long long> g[100100];
int main()
{
    long long n,cnt=0,idx,num,i,sum=0;
    scanf("%lld",&n);
    for(i=0;i<n;i++){
        scanf("%lld",&num);
        idx=upper_bound(a,a+cnt,num)-a;
        if(idx==cnt){
            cnt++;
        }
        a[idx]=num;
        g[idx].push_back(num);
    }
    num=0;
    for(auto x:g[cnt-1]){
        num=max(num,x);
    }
    sum=num;
    for(i=cnt-2;i>=0;i--){
        for(auto x:g[i]){
            if(x<=num){
                num=x;
                sum+=x;
                break;
            }
        }
    }
    printf("%lld %lld\n",cnt,sum);
    return 0;
}
/*
7
2 3 5 5 4 4 1

20
100000000 100000001 100000005 100000003 1000000000
100000000 100000001 100000005 100000003 1000000000
100000000 100000001 100000005 100000003 1000000000
100000000 100000001 100000005 100000003 1000000000

20
0 1 5 3 10
0 1 5 3 10
0 1 5 3 10
0 1 5 3 10

*/
