/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long a[4][4];
};
A tmp;
A mul(A a, A b){
    int i,j,k;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            tmp.a[i][j]=0;
            for(k=0;k<4;k++){
                tmp.a[i][j]+=a.a[i][k]*b.a[k][j];
                tmp.a[i][j]%=10000019;
            }
        }
    }
    return tmp;
}
A m[45],ans;
int main()
{
	long long q,n,i;
	scanf("%lld",&q);
	m[0]={0,0,1,0,1,0,1,0,0,0,0,1,0,1,0,0};
	for(i=1;i<=40;i++){
        m[i]=mul(m[i-1],m[i-1]);
	}
	while(q--){
        ans={1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        scanf("%lld",&n);
        n--;
        for(i=0;i<=40;i++){
            if(n&(1ll<<i))ans=mul(m[i],ans);
        }
        printf("%lld ",ans.a[0][0]);
        printf("%lld ",ans.a[1][0]);
        printf("%lld ",ans.a[2][0]);
        printf("%lld\n",ans.a[3][0]);
	}
    return 0;
}
