/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int s,e;
    bool operator<(const A&o)const{
        if(s!=o.s) return s>o.s;
        return e<o.e;
    }
};
A a[100100];
int dp[100100];
int main()
{
    int q,n,idx,i,cnt;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d %d",&a[i].s,&a[i].e);
        sort(a,a+n);
        cnt=0;
        for(i=0;i<n;i++){
            idx=upper_bound(dp,dp+cnt,a[i].e)-dp;
            if(idx==cnt) cnt++;
            dp[idx] = a[i].e;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
/*
2

3
1 3
3 4
2 2

6
3 4
4 6
11 3
15 2
7 5
1 8
*/
