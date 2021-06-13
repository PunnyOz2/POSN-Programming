/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long three[21]={1,3,9,27,81,243,729,2187,6561,19683,59049,177147,531441,1594323,4782969,14348907,43046721,129140163,387420489,1162261467};
long long Min=1<<30,mark[21],a[25];
stack<long long> q;
int main()
{
    long long n,i,cou,nn;
    scanf("%lld",&n);
    nn=n;
    while(n>=3){
        q.push({n%3});
        n/=3;
    }
    q.push(n);
    cou=0;
    while(!q.empty()){
        a[++cou]=q.top();
        q.pop();
    }
    n=cou;
    cou=0;
    long long left=0;
    long long sum=0;
    for(i=n;i>=0;i--){
        if(a[i]==0 && left==1){
            sum+=three[n-i];
            cou++;
            left=0;
        }
        else if(a[i]==2 && left==0){
            cou++;
            left=1;
        }
        else if(a[i]==1 && left==1){
            cou++;
            left=1;
        }
        else if(a[i]==2 && left==1){
            left=1;
        }
        else if(a[i]==1 && left==0){
            sum+=three[n-i];
            cou++;
        }
    }
    printf("%lld %lld\n",cou,sum);
    return 0;
}
