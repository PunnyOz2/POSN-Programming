#include<bits/stdc++.h>
using namespace std;
struct A{
    long long a[2][2];
};
A mul(A a,A b){
    A tmp;
    int i,j,k;
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            tmp.a[i][j]=0;
            for(k=0;k<2;k++){
                tmp.a[i][j]+=a.a[i][k]*b.a[k][j];
                tmp.a[i][j]%=6427;
            }
        }
    }
    return tmp;
}
A m[50],ans;
int main()
{
	long long n,i,ch;
	scanf("%lld",&n);
	n++;
	if(n==0){printf("1\n");return 0;}
    m[0]={1,1,1,0};
    ans={1,0,0,1};
	for(i=1;i<=40;i++){
        m[i]=mul(m[i-1],m[i-1]);
	}
	for(i=0;i<=40;i++){
        if(n&(1ll<<i))ans=mul(ans,m[i]);
	}
	printf("%lld\n",ans.a[0][1]);
    return 0;
}
