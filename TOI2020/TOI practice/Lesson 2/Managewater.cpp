#include<bits/stdc++.h>
using namespace std;
long long fw[2020][2020],n;
void update(long long x,long long y,long long val){
    long long temp;
    temp=y;
    while(x<=2010){
        y=temp;
        while(y<=2010){
            fw[x][y]+=val;
            y+=(y&-y);
        }
        x+=(x&-x);
    }
}
long long query(long long x,long long y){
    long long sum=0,temp;
    temp=y;
    while(x>0){
        y=temp;
        while(y>0){
            sum+=fw[x][y];
            y-=(y&-y);
        }
        x-=(x&-x);
    }
    return sum;
}
int main(){
    long long n,x,y,val,c,xx,yy;
    scanf("0 %lld",&n);
    while(1){
        scanf("%lld",&c);
        if(c==3)break;
        if(c==1){
            scanf("%lld %lld %lld",&x,&y,&val);
            x++,y++;
            update(x,y,val);
        }
        if(c==2){
            scanf("%lld %lld %lld %lld",&x,&y,&xx,&yy);
            x++,y++,xx++,yy++;
            printf("%lld\n",query(xx,yy)-query(xx,y-1)-query(x-1,yy)+query(x-1,y-1));
        }
    }
    return 0;
}
/*
0 4
1 1 2 3
2 0 0 2 2
1 1 1 2
1 1 2 -1
2 1 1 2 3
3
*/
