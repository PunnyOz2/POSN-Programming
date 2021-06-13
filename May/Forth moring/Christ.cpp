/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long Min=(1<<31)-1,Minabs=(1<<31)-1,a[1900];
int main()
{
    long long n,num,sum=0,i,ans;
    scanf("%lld",&n);
    int now=n*(n-1)/2,last=0;
    for(i=1;i<=n;i++){
        scanf("%lld",&num);
        sum+=num;
    }
    for(i=0;i<=1800;i++){
        a[i]=(1<<31)-1;
    }
    for(i=1;i<=sum;i++){
        if(abs(i*now-sum)>Minabs)break;
        else {
            ans=i;
            if(Minabs==abs(i*now-sum)){
                Min=min(Min,sum-i*now);
            }
            else{
                Minabs=abs(i*now-sum);
                Min=sum-i*now;
            }
        }
    }
    printf("%d\n",ans);
    printf("%lld\n",a[Minabs]);
    return 0;
}
/*
4
0 2 3 5
*/
