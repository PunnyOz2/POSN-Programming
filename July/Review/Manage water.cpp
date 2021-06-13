/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long sum[2010][2010],n;
char com[50];
void update(long long a,long long b,long long c){
    int i,j;
    for(i=a;i<=n+3;i+=(i&-i)){
        for(j=b;j<=n+3;j+=(j&-j)){
            sum[i][j]+=c;
        }
    }
}
long long query(long long x,long long y){
    long long ans=0,i,j;
    for(i=x;i>0;i-=(i&-i)){
        for(j=y;j>0;j-=(j&-j)){
            ans+=sum[i][j];
        }
    }
    return ans;
}
int main()
{
    long long com,x,y,c,xx,yy;
    scanf("%lld %lld",&com,&n);
    while(1){
        scanf("%lld",&com);
        if(com==1){
            scanf("%lld %lld %lld",&x,&y,&c);
            x++,y++;
            update(x,y,c);
        }
        if(com==2){
            scanf("%lld %lld %lld %lld",&x,&y,&xx,&yy);
            x++,y++,xx++,yy++;
            printf("%lld\n",query(xx,yy)-query(x-1,yy)-query(xx,y-1)+query(x-1,y-1));
        }
        if(com==3){
            break;
        }
    }
    return 0;
}
