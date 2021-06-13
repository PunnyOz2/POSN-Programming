#include<bits/stdc++.h>
using namespace std;
char a[10];
long long fw[500100],n;
void add(long long i,long long val){
    while(i<=500003){
        fw[i]+=val;
        i+=(i&-i);
    }
}
long long query(long long i){
    long long sum=0;
    while(i>0){
        sum+=fw[i];
        i-=(i&-i);
    }
    return sum;
}
int main(){
    long long n,q,x,y,val;
    scanf("%lld %lld",&n,&q);
    while(q--){
        scanf(" %s",a);
        if(a[0]=='Y'){
            scanf("%lld %lld %lld",&val,&x,&y);
            if(x>y)swap(x,y);
            add(x,val);
            add(y+1,-val);
        }
        else{
            scanf("%lld",&x);
            printf("%lld\n",query(x));
        }
    }
    return 0;
}
/*
7 6
Y 10 4 7
Y 15 1 5
A 4
Y 5 3 6
A 5
A 7
*/
