#include<bits/stdc++.h>
using namespace std;
struct A{
    long long i,val;
    bool operator<(const A&o)const{
        return i<o.i;
    }
};
A a[200100];
long long colorcou[4];
char c;
int main(){
    long long n,m,l,r,cou=0,i,col;
    scanf("%lld %lld",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%lld %lld",&l,&r);
        a[cou++]={l,1};
        a[cou++]={r+1,-1};
    }
    a[cou++]={1,0};
    a[cou++]={n+1,0};
    sort(a,a+cou);
    col=0;
    for(i=0;i<cou-1;i++){
        if(a[i].i==n+1)break;
        col=((col+a[i].val)+3)%3;
        while(a[i].i==a[i+1].i)i++,col=((col+a[i].val)+3)%3;
        colorcou[col]+=a[i+1].i-a[i].i;
//        printf("%d\n",a[i].i);
//        printf("%d %d\n",col,colorcou[col]);
    }
    //for(i=0;i<3;i++)printf("%d ",colorcou[i]);
    scanf(" %c",&c);
    long long sum=0;
    if(c=='R'){
        sum+=colorcou[1]*2;
        sum+=colorcou[2]*1;
    }
    if(c=='G'){
        sum+=colorcou[0]*1;
        sum+=colorcou[2]*2;
    }
    if(c=='B'){
        sum+=colorcou[0]*2;
        sum+=colorcou[1]*1;
    }
    printf("%lld\n",sum);
    return 0;
}
/*
4 4
1 2
2 3
3 4
3 3
R

3 2
1 2
2 3
R
*/
