/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long num;
long long b[3000100],mid,cou,l,r,k;
int main()
{
    int Q,n,i;
    scanf("%d",&Q);
    while(Q--){
        scanf("%d %lld",&n,&k);
        for(i=1;i<=1500010;i++)b[i]=1e9;
        for(i=1;i<=n;i++){
            scanf(" %d",&num);
            b[num+300000]=0;
        }
        for(i=2;i<=1500010;i++){
            b[i]=min(b[i],b[i-1]+1);
        }
        for(i=1500010-1;i>=1;i--){
            b[i]=min(b[i],b[i+1]+1);
        }
        l=0;
        r=1e9;
        while(l<r){
            mid=(l+r)/2;
            //printf("%lld ",mid);
            cou=0;
            for(i=1;i<=1500010;i++){
                cou+=max(0ll,mid+1-b[i]);
            }
            //printf("%lld\n",cou);
            if(cou>=k)r=mid;
            else l=mid+1;
        }
        printf("%lld\n",l);
    }
    return 0;
}
/*
3
3 10
0 5 6
3 30
0 6 5
2 10
0 0
*/
