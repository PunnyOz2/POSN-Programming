/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int pos,time,id;
    bool operator<(const A&o)const{
        return time<o.time;
    }
};
struct B{
    int pos,time,id;
    bool operator<(const B&o)const{
        return pos<o.pos;
    }
};
A a[100100];
B b[100100];
int ans[100100];
int main()
{
    int n,m,i,cou,ch,j,ll,rr,temp;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d %d",&a[i].pos,&a[i].time);
        a[i].time+=i-1;
        a[i].id=i;
    }
    sort(a+1,a+n+1);
    cou=0;
    for(i=1;i<=n;i++){
        ch=1;
        for(j=1;j<=cou;j++){
            if((b[j].pos>a[i].pos && b[j].pos-(a[i].time-b[j].time)>=a[i].pos) || (b[j].pos<a[i].pos&&b[j].pos+(a[i].time-b[j].time)<=a[i].pos)){}
            else{
                ch=0;
            }
        }
        if(ch==1){
            cou++;
            b[cou].pos=a[i].pos;
            b[cou].time=a[i].time;
            b[cou].id=a[i].id;
        }
    }
    sort(b+1,b+cou+1);
//    for(i=1;i<=cou;i++){
//        printf("%d %d\n",b[i].time,b[i].pos);
//    }
    for(i=1;i<=cou;i++){
        if(i==1){
            ll=0;
            if(b[i].time>b[i+1].time){
                temp=b[i+1].pos-(b[i].time-b[i+1].time);
            }
            else{
                temp=b[i+1].pos+(b[i+1].time-b[i].time);
            }
            //printf("A %d %d\n",temp,b[i].pos);
            temp=(temp+b[i].pos)/2;
            rr=temp;
            if(b[i].id>b[i+1].id){
                rr--;
            }
            ans[b[i].id]=rr-ll+1;
        }
        else if(i==cou){
            rr=m;
            if(b[i].time>b[i-1].time){
                temp=b[i-1].pos+(b[i].time-b[i-1].time);
            }
            else{
                temp=b[i-1].pos-(b[i-1].time-b[i].time);
            }
            //printf("A %d %d\n",temp,b[i].pos);
            temp=(temp+b[i].pos)/2;
            ll=temp;
            if(b[i].id>b[i-1].id){
                ll++;
            }
            ans[b[i].id]=rr-ll+1;
        }
        else{
            if(b[i].time>b[i+1].time){
                temp=b[i+1].pos-(b[i].time-b[i+1].time);
            }
            else{
                temp=b[i+1].pos+(b[i+1].time-b[i].time);
            }
            temp=(temp+b[i].pos)/2;
            rr=temp;
            if(b[i].time>b[i-1].time){
                temp=b[i-1].pos+(b[i].time-b[i-1].time);
            }
            else{
                temp=b[i-1].pos-(b[i-1].time-b[i].time);
            }
            temp=(temp+b[i].pos)/2;
            ll=temp;
            if(b[i].id>b[i+1].id){
                rr--;
            }
            if(b[i].id>b[i-1].id){
                ll++;
            }
            ans[b[i].id]=rr-ll+1;
        }
    }
    for(i=1;i<=n;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}
/*
3 9
4 3
7 1
8 4
*/
