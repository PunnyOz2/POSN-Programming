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
A tmp[65];
A ans;
A temp;
long long b,c,n;
A mul(A a,A b){
    int i,j,k;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            temp.a[i][j]=0;
            for(k=1;k<=n;k++){
                temp.a[i][j]+=(a.a[i][k]%c)*(b.a[k][j]%c);
                temp.a[i][j]%=c;
            }
        }
    }
    return temp;
}
int main()
{
    long long i,j;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%lld",&tmp[0].a[i][j]);
            if(i==j)ans.a[i][j]=1;
        }
    }
    scanf("%lld %lld",&b,&c);
    for(i=1;i<=61;i++){
        tmp[i]=mul(tmp[i-1],tmp[i-1]);
    }
    for(i=1;i<=61;i++){
        if((b&(1ll<<(i-1))))ans=mul(tmp[i-1],ans);
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)printf("%lld ",ans.a[i][j]);
        printf("\n");
    }
    return 0;
}
/*
2
5 8
21 6
2 100
*/
