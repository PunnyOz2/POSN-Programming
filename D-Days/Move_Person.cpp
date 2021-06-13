/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[5010];
int lis[5010],temp[5010];
int main()
{
    int n,m,i,idxtemp,idx,cnt=0;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        temp[i]=a[i];
    }
    sort(temp,temp+n);
    for(i=0;i<n;i++){
        idxtemp=upper_bound(temp,temp+n,a[i])-temp;
        idxtemp--;
        idxtemp/=m;
        //printf("%d ",idxtemp);
        idx=upper_bound(lis,lis+cnt,idxtemp)-lis;
        if(idx==cnt)cnt++;
        lis[idx]=idxtemp;
    }
    printf("%d\n",n-cnt);
    return 0;
}
/*
6 3
10 12 11 4 8 6

6 2
8 2 3 5 4 6
*/
