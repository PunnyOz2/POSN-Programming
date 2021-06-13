/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long a[7][7];
};
A temp;
A mul(A a,A b){
     long long i,j,k;
     for(i=0;i<7;i++){
        for(j=0;j<7;j++){
            temp.a[i][j]=0;
            for(k=0;k<7;k++){
                temp.a[i][j]+=a.a[i][k]*b.a[k][j];
                temp.a[i][j]%=1000000007;
            }
        }
     }
     return temp;
}
A ans,p[35];
int main()
{
    long long n,i;
    p[0]={0,0,1,0,0,0,1,
          1,0,0,1,0,1,0,
          0,0,1,0,1,0,1,
          1,0,0,1,0,1,0,
          0,1,1,0,1,0,0,
          0,1,0,0,1,0,0,
          1,0,0,1,0,1,0};
    scanf("%lld",&n);
    for(i=0;i<7;i++){
        ans.a[0][i]=1;
    }
    for(i=1;i<=30;i++){
        p[i]=mul(p[i-1],p[i-1]);
    }
    for(i=0;i<=30;i++){
        if((n-1)&(1<<i))    ans=mul(ans,p[i]);
    }
    long long sum=0;
    for(i=0;i<7;i++){
        sum+=ans.a[0][i];
//        printf("%lld ",ans.a[0][i]);
        sum%=1000000007;
    }
    printf("%lld\n",sum);
    return 0;
}
