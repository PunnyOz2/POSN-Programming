#include<bits/stdc++.h>
#include "rescues.h"
#include "rescuelib.cpp"
//void get_size(int n,int m);
//int drop_robot(int n,int m);
//void answer(int n,int m);
using namespace std;
int main()
{
    int n,m,cou=0,a,b,c,d,chy,chx,l,r,now,mid,po1,po2,x,y;
    get_size(n,m);
    a=drop_robot(n,1);
    b=drop_robot(n,m);
    c=drop_robot(1,1);
    d=drop_robot(1,m);
    if(a==0)cou++;
    if(b==0)cou++;
    if(c==0)cou++;
    if(d==0)cou++;
    if(cou==3){
        if(a!=0)chy=n,chx=1;
        if(b!=0)chy=n,chx=m;
        if(c!=0)chy=1,chx=1;
        if(d!=0)chy=1,chx=m;
        l=1;
        r=m;
        //horizon
        now=0;
        if(chx=m)now=1;
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
        //vertical
        now=0;
        if(chy=n)now=1;
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
        if(a!=0){
            y=(a+drop_robot(chx,po2)-1+abs(chy-po2))/2;
            x=(a+drop_robot(po1,chy)-1+abs(chx-po1))/2;
            answer(x,y);
        }
        if(b!=0){
            y=(b+drop_robot(chx,po2)-1+abs(chy-po2))/2;
            x=(b+drop_robot(po1,chy)-1+abs(chx-po1))/2;
            answer(x,y);
        }
        if(c!=0){
            y=(c+drop_robot(chx,po2)-1+abs(chy-po2))/2;
            x=(c+drop_robot(po1,chy)-1+abs(chx-po1))/2;
            answer(x,y);
        }
        if(d!=0){
            y=(d+drop_robot(chx,po2)-1+abs(chy-po2))/2;
            x=(d+drop_robot(po1,chy)-1+abs(chx-po1))/2;
            answer(x,y);
        }
    }
    if(cou==2){
        if(a!=0 && b!=0){

        }
        if(a!=0 && c!=0){

        }
        if(d!=0 && b!=0){

        }
        if(d!=0 && c!=0){

        }
    }
    if(cou==0){

    }
    return 0;
}
/*

*/
