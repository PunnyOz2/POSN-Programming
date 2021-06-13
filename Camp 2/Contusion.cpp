/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,y,c,l,r,ll,rr,u,d,mid,cou;
    scanf("%d %d %d %d",&n,&x,&y,&c);
    l=0;r=n*3;
    u=n-x+1;
    d=x;
    ll=y;
    rr=n-y+1;
    while(l<r){
        mid=(l+r)/2;
        cou=2*(mid+1)*(mid+1)-2*(mid+1)+1;
        printf("%d %d\n",mid,cou);
        if(u<=mid)cou-=(mid-u+1)*(mid-u+1);
        if(d<=mid)cou-=(mid-d+1)*(mid-d+1);
        if(ll<=mid)cou-=(mid-ll+1)*(mid-ll+1);
        if(rr<=mid)cou-=(mid-rr+1)*(mid-rr+1);
        printf("%d\n",cou);
        //printf("%d %d\n",u,rr);
        if(mid-u==ll)cou+=(min(mid-u,mid-ll))*(min(mid-u,mid-ll)+1)/2;
        printf("%d\n",cou);
        if(mid-u==rr)cou+=(min(mid-u,mid-rr))*(min(mid-u,mid-rr)+1)/2;
        printf("%d\n",cou);
        if(mid-ll==d)cou+=(min(mid-ll,mid-d))*(min(mid-ll,mid-d)+1)/2;
        printf("%d\n",cou);
        if(mid-rr==d)cou+=(min(mid-rr,mid-d))*(min(mid-rr,mid-d)+1)/2;
        printf("%d\n",cou);
        if(cou>=c)r=mid;
        else l=mid+1;
    }
    if(l==n*3)printf("0\n");
    else printf("%d\n",l);
    return 0;
}
/*
6 4 3 1
3 3 3 4
9 3 8 10
*/
