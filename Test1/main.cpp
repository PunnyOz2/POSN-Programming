#include <iostream>
#include "rescuelib.cpp"

using namespace std;

int R,C;

int main()
{
    int n,m,cou=0,a,b,c,d,chy,chx,l,r,now,mid,po1,po2,x,y;
    get_size(n,m);
    a=drop_robot(n,1);
    b=drop_robot(n,m);
    c=drop_robot(1,1);
    d=drop_robot(1,m);
    if(a==-1)cou++;
    if(b==-1)cou++;
    if(c==-1)cou++;
    if(d==-1)cou++;
    if(cou==3){
        if(a!=-1)chy=1,chx=n;
        if(b!=-1)chy=m,chx=n;
        if(c!=-1)chy=1,chx=1;
        if(d!=-1)chy=m,chx=1;
        l=1;
        r=m;
        //horizon
        now=0;
        if(chx==m)now=1;
        while(l<r){
            mid=(l+r+now)/2;
            if(drop_robot(mid,chy)==0){
                if(now==1)l=mid+1;
                else r=mid-1;
            }
            else{
                if(now==1)r=mid;
                else l=mid;
            }
        }
        po1=l;
        //vertical
        now=0;
        l=1;
        r=n;
        if(chy==n)now=1;
        while(l<r){
            mid=(l+r+now)/2;
            if(drop_robot(chx,mid)==0){
                if(now==1)l=mid+1;
                else r=mid-1;
            }
            else{
                if(now==1)r=mid;
                else l=mid;
            }
        }
        po2=l;
        if(a!=0){
            x=(a+drop_robot(chx,po2)-1-abs(chy-po2))/2;
            y=(a+drop_robot(po1,chy)-1-abs(chx-po1))/2;
            answer(x+1,n-y);
        }
        if(b!=0){
            x=(b+drop_robot(chx,po2)-1-abs(chy-po2))/2;
            y=(b+drop_robot(po1,chy)-1-abs(chx-po1))/2;
            answer(m-x,n-y);
        }
        if(c!=0){
            x=(c+drop_robot(chx,po2)-1-abs(chy-po2))/2;
            y=(c+drop_robot(po1,chy)-1-abs(chx-po1))/2;
            answer(x+1,y+1);
        }
        if(d!=0){
            x=(d+drop_robot(chx,po2)-1-abs(chy-po2))/2;
            y=(d+drop_robot(po1,chy)-1-abs(chx-po1))/2;
            answer(m-x,y+1);
        }
    }
    if(cou==2){
        if(a!=-1 && b!=-1){
            now=1;
            l=1;
            r=n;
            while(l<r){
                mid=(l+r+now)/2;
                if(drop_robot(n,mid)==0){
                    if(now==1)l=mid+1;
                    else r=mid-1;
                }
                else{
                    if(now==1)r=mid;
                    else l=mid;
                }
            }
            po2=l;
            x=(a+drop_robot(po2,n)-1-abs(n-po2))/2;
            y=(a+b-1-m+1)/2;
            answer(x+1,n-y);
        }
        if(a!=-1 && c!=-1){
            l=1;
            r=m;
            //horizon
            now=0;
            if(chx==m)now=1;
            while(l<r){
                mid=(l+r+now)/2;
                if(drop_robot(chy,mid)==0){
                    if(now==1)l=mid+1;
                    else r=mid-1;
                }
                else{
                    if(now==1)r=mid;
                    else l=mid;
                }
            }
            po1=l;
        }
        if(d!=-1 && b!=-1){

        }
        if(d!=-1 && c!=-1){
            now=0;
            l=1;
            r=n;
            while(l<r){
                mid=(l+r+now)/2;
                if(drop_robot(mid,chx)==0){
                    if(now==1)l=mid+1;
                    else r=mid-1;
                }
                else{
                    if(now==1)r=mid;
                    else l=mid;
                }
            }
            po2=l;
            x=(c+drop_robot(1,po2)-1-abs(1-po2))/2;
            y=(c+b-1-m+1)/2;
            answer(x+1,y+1);
        }
    }
    if(cou==0){
        y=(c+d-1-m+1)/2;
        x=(c+a-1-n+1)/2;
        answer(y+1,x+1);
    }
    return 0;
}
