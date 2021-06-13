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
    long long a[220][220];
};
A temp;
void mul(A &a,A &b){
    int i,j,k;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            temp.a[i][j]=0;
            for(k=1;k<=n;k++){
                temp.a[i][j]+=(a.a[i][k]%10007*b.a[k][j]%10007)%10007;
                temp.a[i][j]%10007;
            }
        }
    }
}
A m[33],ans;
int main()
{
    long long nn,d,i,x,y;
    scanf("%lld %lld %lld",&n,&nn,&d);
    for(i=1;i<=n;i++){
        m[0].a[i][i]=1ll;
    }
    for(i=1;i<=nn;i++){
        scanf("%lld %lld",&x,&y);
        m[0].a[x][y]=1ll;
        m[0].a[y][x]=1ll;
    }
    ans.a[1][1]=1ll;
    for(i=1;i<=30;i++){
        mul(m[i-1],m[i-1]);
        m[i]=temp;
    }
    for(i=0;i<=30;i++){
        if(d&(1ll<<i)){
            mul(m[i],ans);
            ans=temp;
        }
    }
    for(i=1;i<=n;i++){
        printf("%lld ",ans.a[i][1]%10007);
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
