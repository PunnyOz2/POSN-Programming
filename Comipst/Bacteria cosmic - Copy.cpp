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
        return pos<o.pos;
    }
};
struct B{
    int pos,time,id;
    bool operator<(const B&o)const{
        return pos<o.pos;
    }
};
A a[100100];
A b[100100];
int ans[100100];
stack<A> st;
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
    for(i=1;i<=n;i++){
        ch=1;
        temp=0;
        while(!st.empty() && st.top().time>a[i].time){
            if(a[i].id>st.top().id)temp=0;
            else temp=1;
            if(a[i].pos-(st.top().time-a[i].time)+temp<=st.top().pos)st.pop();
            else break;
        }
        if(!st.empty() && st.top().time<a[i].time){
            if(a[i].id<st.top().id)temp=-1;
            else temp=0;
            if(st.top().pos+(a[i].time-st.top().time)+temp>a[i].pos)ch=0;
        }
        if(ch==1)st.push(a[i]);
    }
    cou=0;
    while(!st.empty()){
        b[++cou]=st.top();
        st.pop();
    }
    sort(b+1,b+cou+1);
    for(i=1;i<=cou;i++){
        if(1==cou){
            ll=0;
            rr=m;
            ans[b[i].id]=rr-ll+1;
        }
        else if(i==1){
            ll=0;
            if(b[i].time>b[i+1].time){
                temp=b[i+1].pos-(b[i].time-b[i+1].time);
            }
            else{
                temp=b[i+1].pos+(b[i+1].time-b[i].time);
            }
            temp=(temp+b[i].pos)/2;
            rr=temp;
            if(b[i].id>b[i+1].id)rr--;
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
            temp=(temp+b[i].pos)/2;
            ll=temp;
            if(b[i].id>b[i-1].id)ll++;
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
            if(b[i].id>b[i+1].id)rr--;
            if(b[i].id>b[i-1].id)ll++;
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
