/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j;
    bool operator<(const A&o)const{
        if(i!=o.i)return i<o.i;
        return j>o.j;
    }
};
int lis[100100];
A a[100100];
int main()
{
    int q,i,n,cnt,idx;
    scanf("%d",&q);
    while(q--){
        cnt=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)scanf("%d %d",&a[i].i,&a[i].j);
        sort(a+1,a+n+1);
        for(i=1;i<=n;i++){
            idx=upper_bound(lis,lis+cnt,-a[i].j)-lis;
            if(idx==cnt)cnt++;
            lis[idx]=-a[i].j;
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
