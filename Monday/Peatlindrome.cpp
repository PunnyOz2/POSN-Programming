/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long a[1000010];
int main()
{
    long long q,n,idx1,idx2,sum1,sum2,cou,i,sum;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld",&n);
        for(i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        idx1=1;
        idx2=n;
        sum=0;
        cou=0;
        while(idx1<idx2){
            if(a[idx1]==a[idx2])    ++idx1,--idx2;
            else if(a[idx1]<a[idx2])    a[idx1+1]+=a[idx1],idx1++,cou++;
            else     a[idx2-1]+=a[idx2],idx2--,cou++;
        }
        printf("%lld\n",cou);
    }
    return 0;
}
/*
1
4
2 2 3 1

5
4 6 2 3 3

1
3
1 2 3
*/
