/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long n;
struct A{
    long long a[205][205];
};
A mul(A a,A b){
    A temp;
    long long i,j,k;
    //printf("Hi\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            temp.a[i][j]=0;
            for(k=1;k<=n;k++){
                temp.a[i][j]+=(a.a[i][k]*b.a[k][j]);
                temp.a[i][j]%=10007;
            }
        }
    }
    return temp;
}
A m[40],ans;
int main()
{
    long long M,k,i,u,v;
    scanf("%lld %lld %lld",&n,&M,&k);
    for(i=1;i<=n;i++){
        m[0].a[i][i]=1;
    }
    for(i=0;i<M;i++){
        scanf("%lld %lld",&u,&v);
        m[0].a[u][v]=m[0].a[v][u]=1;
    }
    for(i=1;i<=35;i++){
        m[i]=mul(m[i-1],m[i-1]);
    }
    //printf("Hi\n");
    ans.a[1][1]=1;
    for(i=0;i<=35;i++){
        if((k&(1ll<<i)))ans=mul(m[i],ans);
    }
    for(i=1;i<=n;i++){
        printf("%lld ",ans.a[i][1]);
    }
    return 0;
}
/*
5 5 3
1 2
2 3
2 4
3 5
4 5
*/
