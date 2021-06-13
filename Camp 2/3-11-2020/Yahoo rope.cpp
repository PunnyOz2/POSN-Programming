/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010],b[1010],c[1010];
int lis[1010];
int main()
{
    int q,n,cnt,i,idx,Max;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        cnt=0;
        for(i=1;i<=n;i++){
            idx=lower_bound(lis,lis+cnt,a[i])-lis;
            if(idx==cnt)cnt++;
            lis[idx]=a[i];
            b[i]=cnt;
        }
        cnt=0;
        for(i=n;i>=1;i--){
//        printf("HI\n");
            idx=lower_bound(lis,lis+cnt,a[i])-lis;
            if(idx==cnt)cnt++;
            lis[idx]=a[i];
            c[i]=cnt;
        }
        Max=0;
        for(i=1;i<n;i++){
            //if(a[i]==a[i+1])continue;
            Max=max(Max,b[i]+c[i]-1);
        }
        printf("%d\n",Max);
    }
    return 0;
}
/*
1
18
0 2 8 4 3 2 4 1 8 5 7 1 3 9 6 4 2 0
*/
