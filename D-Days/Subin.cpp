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
        if(i!=o.i) return i<o.i;
        return j>o.j;
    }
};
A a[100100];
int lis[100100];
int main()
{
    int n,i,idx;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d",&a[i].i,&a[i].j);
    }
    sort(a,a+n);
    int cnt=0;
    for(i=0;i<n;i++){
        idx=upper_bound(lis,lis+cnt,-1*a[i].j)-lis;
        if(idx==cnt)cnt++;
        lis[idx]=a[i].j*-1;
    }
    printf("%d\n",cnt);
    return 0;
}
/*
6
1 5
1 6
1 4
1 7
3 5
2 5
*/
