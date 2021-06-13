#include<bits/stdc++.h>
using namespace std;
struct Y{
    long long x,y;
};
struct W{
    long long x,y,r;
};
Y yak[200];
W wall[30100];
long long couy[30100];
long long m,n;
int main(){
    long long i,j,x1,x2,y1,y2,r2,distancew;
    scanf("%lld %lld",&m,&n);
    for(i=1;i<=m;i++){
        scanf("%lld %lld",&yak[i].x,&yak[i].y);
    }
    for(i=1;i<=n;i++){
        scanf("%lld %lld %lld",&wall[i].x,&wall[i].y,&wall[i].r);
    }
    for(i=1;i<=m;i++){
        x1=yak[i].x;
        y1=yak[i].y;
        for(j=1;j<=n;j++){
            x2=wall[j].x;
            y2=wall[j].y;
            r2=wall[j].r;
            distancew=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
            if(distancew-r2*r2<0)couy[j]++;
        }
    }
    long long ans=0;
    for(i=1;i<=n;i++){
        if(couy[i]>0 &&couy[i]!=m)ans++;
    }
    printf("%lld\n",ans);
}
/*
4 7
6 10
5 16
12 5
16 10
6 16 2
6 15 4
11 16 1
5 6 3
11 7 1
15 2 1
16 10 2
*/
