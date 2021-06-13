/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int dis,mon,u,time;
    bool operator<(const A&o)const{
        return dis<o.dis;
    }
};
int n,c,d;
struct B{
    int dis,mon,u,time;
    bool operator<(const B&o)const{
        return time<o.time;
    }
};
B b[500100];
A a[500100];
int cou;
//int play(int now,int dis,int sum){
//    if(now>cou)return 0;
//    int Max=0;
//    Max=max(Max,play(now+1,dis,sum));
//
//    if(dis>b[now+1].dis)    Max=max(Max,play(now+1,b[now+1].dis,sum+(dis-b[now+1].dis)*d)+b[now].mon);
//    else                    Max=max(Max,play(now+1,b[now+1].dis,sum+(b[now+1].dis-dis)*c)+b[now].mon);
//    printf("%d\n",Max);
//    return Max;
//}
int Max=0,sti;
int play(int now,int dis){
    if(now>cou)return 0;
    int aa,bb;
    aa=play(now+1,dis);
    bb=play(now+1,b[now].dis);
    if(dis>b[now].dis)bb+=-1*(dis-b[now].dis)*d+b[now].mon;
    else bb+=-1*(b[now].dis-dis)*c+b[now].mon;

    if(a[sti].dis>=dis)Max=max(Max,aa-(a[sti].dis-dis)*d);
    else Max=max(Max,aa-(dis-a[sti].dis)*c);
    return max(aa,bb);
}
int main()
{
    int i;
    scanf("%d %d %d %d",&n,&c,&d,&a[0].dis);
    for(i=1;i<=n;i++){
        scanf("%d %d %d",&a[i].time,&a[i].dis,&a[i].mon);
        a[i].u=i;
    }
    sort(a,a+n+1);
    for(i=0;i<=n;i++){
        if(a[i].u==0){
//            for(j=0;j<=i-1;j++){
//                a[j].dis=a[j+1].dis-a[j].dis;
//            }
//            for(j=n;j>=i+1;j--){
//                a[j].dis=a[j-1].dis-a[j].dis;
//            }
//            a[i].dis=0;
            sti=i;
            break;
        }
    }
    cou=1;
    for(i=0;i<=n;i++){
        if(i==sti)continue;
        b[cou].dis=a[i].dis;
        b[cou].mon=a[i].mon;
        b[cou].u=a[i].u;
        b[cou++].time=a[i].time;
    }
    sort(b+1,b+1+cou);
    printf("%d\n",play(1,a[sti].dis));
//    int dis,mon,u,time;
//    if(a[sti].dis>b[1].dis)play(b[1].time,a[sti]-b[1].dis);
//    if(a[sti].dis<b[1].dis)play(b[1].time,b[1].dis-a[sti]);
    return 0;
}
/*
4 5 3 100
2 80 100
20 125 130
10 75 150
5 120 110
*/
