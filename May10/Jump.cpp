/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int x,y,val;
    bool operator<(const A&o)const {
        if(max(x,y)!=max(o.x,o.y)) return max(x,y)<max(o.x,o.y);
        return min(x,y)<min(o.x,o.y);
    }
};
A a[300100];
int dpx[100100],dpy[100100];
int main()
{
    int n,b,val,stx,sty,i,enx,eny,now1,now2;
    scanf("%d %d",&n,&b);
    scanf("%d %d %d",&stx,&sty,&val);
    dpx[stx]=dpy[sty]=val;
    for(i=1;i<n;i++){
        scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].val);
    }
    enx=a[n-1].x;
    eny=a[n-1].y;
    sort(a+1,a+n);
    for(i=1;i<n;i++){
        if(a[i].x<stx || a[i].y<sty)continue;
        now1=0;
        now2=0;
        if(dpx[a[i].x]>=b){
            now1=dpx[a[i].x]-b+a[i].val;
        }
        if(dpy[a[i].y]>=b){
            now2=dpy[a[i].y]-b+a[i].val;
        }
        dpx[a[i].x]=max(dpx[a[i].x],max(now1,now2));
        dpy[a[i].y]=max(dpy[a[i].y],max(now1,now2));
        if(a[i].x==enx && a[i].y==eny){printf("%d",max(now1,now2));break;}
    }
    return 0;
}
/*
6 5
1 1 5
2 1 5
1 2 4
2 3 5
3 2 30
3 3 5
*/
