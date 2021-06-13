/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    double a[251][251];
};
int n;
A tmp;
void mul(A *a,A *b){
    int i,j,k;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            tmp.a[i][j]=0;
            for(k=1;k<=n;k++){
                tmp.a[i][j]+=a->a[i][k]*b->a[k][j];
            }
        }
    }
}
A dp[20],ans,mat;
int main()
{
    int t,i,j;
	scanf("%d %d",&n,&t);
	for(i=1;i<=n;i++)scanf("%lf",&ans.a[i][1]);
	for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)scanf("%lf",&dp[0].a[j][i]);
	}
	//printf("Hi\n");
	for(i=1;i<20;i++){
        mul(&dp[i-1],&dp[i-1]);
        dp[i]=tmp;
	}
	for(i=1;i<=n;i++)mat.a[i][i]=1;
	for(i=0;i<20;i++){
        if(t&(1ll<<i)){
            mul(&mat,&dp[i]);
            mat=tmp;
        }
	}
	mul(&mat,&ans);
	ans=tmp;
	for(i=1;i<=n;i++)printf("%.2lf\n",ans.a[i][1]);
    return 0;
}
/*
3 1
30 40 50
0.5 0.2 0.3
0.1 0.4 0.5
0.3 0.3 0.4
*/
