/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long n,m,DIS=1e18,mark[20];
struct A{
    long long x,y,z;
};
A cou[25],a[25];
void play(long long now,long long x,long long y,long long z,long long dis){
    if(x>=n && y>=n && z>=n && dis<DIS){
        DIS=dis;
        return;
    }
    long long i;
    for(i=1;i<=m;i++){
        if(mark[i]==1)continue;
        mark[i]=1;
        play(i,x+cou[i].x,y+cou[i].y,z+cou[i].z,dis+(a[i].x-a[now].x)*(a[i].x-a[now].x) + (a[i].y-a[now].y)*(a[i].y-a[now].y) + (a[i].z-a[now].z)*(a[i].z-a[now].z));
        mark[i]=0;
    }
    return ;
}
int main()
{
    long long i;
    scanf("%lld",&n);
    scanf("%lld %lld %lld",&a[0].x,&a[0].y,&a[0].z);
    scanf("%lld",&m);
    for(i=1;i<=m;i++){
        scanf("%lld %lld %lld",&a[i].x,&a[i].y,&a[i].z);
        scanf("%lld %lld %lld",&cou[i].x,&cou[i].y,&cou[i].z);
    }
    play(0,0,0,0,0);
    printf("%lld\n",DIS);
    return 0;
}
/*
5
0 0 0
5
60 34 56
0 5 7
90 41 92
1 7 8
24 61 81
6 8 8
41 86 70
5 6 7
46 97 85
9 2 4
*/
