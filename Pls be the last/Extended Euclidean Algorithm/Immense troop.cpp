/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int MOD=500000003;
void Euclid(int a,int b,int *x,int *y){
    if(b==0){
        *x=1,*y=0;
        return;
    }
    int u,v;
    Euclid(b,a%b,&u,&v);
    *x = v;
    *y = u-v*(a/b);
    return;
}
int inve(int a,int b){
    int x,y;
    Euclid(a,b,&x,&y);
    return x%b;
}
int main()
{
    int q,x1,x2,y1,y2,n,r,inv,i;
    long long ans;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        if(x1>x2||y1>y2){
            printf("0\n");continue;
        }
        n=x2-x1+y2-y1,r=y2-y1;
        if(n-r>r)r=n-r;
        ans=1;
        for(i=r+1;i<=n;i++)
            ans*=i,ans%=MOD;
        for(i=2;i<=n-r;i++){
            inv = inve(i,MOD);
            if(inv<0)inv+=MOD;
            ans*=inv;ans%=MOD;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
