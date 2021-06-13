/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long a[1000003];
int main()
{
    long long l,k,i,x,y,sum=0;
    scanf("%lld %lld",&l,&k);
    for(i=1;i<=k;i++){
        scanf("%lld %lld",&x,&y);
        sum+=y;
        a[i]=y-x;
    }
    sort(a+1,a+k+1);
    for(i=k;i>0;i--){
        if(l<=0)break;
        if(a[i]<=0)break;
        l--;
        sum-=a[i];
    }
    printf("%lld\n",sum);
    return 0;
}
/*
2 4
1 2
3 2
1 5
3 1
*/
