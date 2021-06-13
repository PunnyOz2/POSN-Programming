/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
struct A{
    long long a[2][2];
};
A tmp;
A mul(A a, A b){
    int i,j,k;
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            tmp.a[i][j]=0;
            for(k=0;k<2;k++){
                tmp.a[i][j]+=a.a[i][k]*b.a[k][j];
                tmp.a[i][j]%=1000000007;
            }
        }
    }
    return tmp;
}
int gcd(int a,int b){
    if(b==0)return a;
    if(a==0)return b;
    if(a%b==0)return b;
    return gcd(b,(a%b));
}
A ans,m[35];
int main()
{
	long long q,i,j,ansnum;
	scanf("%lld",&q);
	m[0]={1,1,1,0};
    for(i=1;i<=30;i++){
        m[i]=mul(m[i-1],m[i-1]);
    }
	while(q--){
        ans={1,0,0,1};
        scanf("%lld %lld",&i,&j);
        ansnum=gcd(i,j);
        if(ansnum==0){printf("1\n");continue;}
        ansnum--;
        for(i=0;i<=30;i++){
            if(ansnum&(1<<i))ans=mul(ans,m[i]);
        }
        printf("%lld\n",ans.a[0][0]);
	}
    return 0;
}
/*
2
7 10
6 12
*/

