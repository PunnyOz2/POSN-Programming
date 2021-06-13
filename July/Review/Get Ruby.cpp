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
    long long n,m,x,y;
    scanf("%lld %lld",&n,&m);
    while(m--){
        scanf(" %s %lld %lld",com,&x,&y);
        if(com[0]=='B'){
            update(x,y);
        }
        else{
            printf("%lld\n",query(y)-query(x-1));
        }
    }
    return 0;
}
