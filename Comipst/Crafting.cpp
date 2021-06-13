/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long a[22],sum;
void play(long long val,long long st){
    if(st==1){
        if(val<=0){
            printf("-1\n");
            exit(0);
        }
        sum+=val;
        return;
    }
    if(val<=0){
        printf("-1\n");
        exit(0);
    }
    val=val*2-a[st-1];
    if(a[st-1]%2==1){
        play(val/2+1,st-1);
        play(val/2+1,st-1);
    }
    else{
        play(val/2+1,st-1);
        play(val/2,st-1);
    }
}
int main()
{
    long long n,m,i,ans;
    scanf("%lld %lld",&n,&m);
    for(i=1;i<=n-1;i++){
        scanf("%lld",&a[i]);
    }
    play(m,n);
    printf("%lld\n",sum);
}
// 3 10 1 2        38
