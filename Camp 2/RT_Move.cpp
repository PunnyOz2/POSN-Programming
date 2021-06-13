/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int temp[5010],a[5010],lis[5010];
int main()
{
    int n,m,i,idx,idx2,cnt;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        temp[i]=a[i];
    }
    sort(temp+1,temp+1+n);
    cnt=0;
    for(i=1;i<=n;i++){
        idx=upper_bound(temp+1,temp+1+n,a[i])-temp-1;
        idx--;
        idx/=m;
        idx2=upper_bound(lis,lis+cnt,idx)-lis;
        if(idx2==cnt)cnt++;
        lis[idx2]=idx;
    }
    printf("%d\n",n-cnt);
    return 0;
}
/*
6 3
10 12 11 4 8 6
*/
