/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long a[2][2];
};
A tmp;
A mul(A a,A b){
    long long i,j,k;
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            tmp.a[i][j]=0;
            for(k=0;k<2;k++){
                tmp.a[i][j]+=(a.a[i][k]%1000000007*b.a[k][j]%1000000007)%1000000007;
                tmp.a[i][j]%=1000000007;
            }
        }
    }
    return tmp;
}
A m[65],ans;
int main()
{
    long long q,i,n;
    scanf("%lld",&q);
    m[0]={1,1,1,0};
    for(i=1;i<=60;i++){
        m[i]=mul(m[i-1],m[i-1]);
        //printf("%lld\n",m[i].a[0][0]);
    }
    while(q--){
        scanf("%lld",&n);
        ans={1ll,0ll,0ll,1ll};
        if(n==0){printf("0\n");continue;}
        if(n==1){printf("1\n");continue;}
        n--;
        for(i=0;i<=60;i++){
            if(n&(1ll<<i))ans=mul(m[i],ans);
        }
        printf("%lld\n",ans.a[0][0]);
    }
    return 0;
}
