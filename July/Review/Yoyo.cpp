/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long fen[750100];
char com[50];
void update(long long a,long long b){
    while(b<=750003){
        fen[b]+=a;
        b+=(b&-b);
    }
}
long long query(int a){
    long long sum=0;
    while(a>0){
        sum+=fen[a];
        a-=(a&-a);
    }
    return sum;
}
int main()
{
    long long n,m,x,y,c;
    scanf("%lld %lld",&n,&m);
    while(m--){
        scanf(" %s",com,&x,&y);
        if(com[0]=='Y'){
            scanf("%lld %lld %lld",&c,&x,&y);
            if(x>y)swap(x,y);
            update(c,x);
            update(-c,y+1);
        }
        else{
            scanf("%lld",&x);
            printf("%lld\n",query(x));
        }
    }
    return 0;
}
