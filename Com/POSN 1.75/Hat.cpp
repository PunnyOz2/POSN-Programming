/*
    TASK: Hat
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int type,w,v,d,x;
    bool operator< (const A& o) const{
        if(w!=o.w) return w >o.w;
    }
};
priority_queue< A > h;
priority_queue< A > h2;
int main()
{
    int n,m,opr1,opr2,w,v,d,x;
    A temp,temp2;
    scanf("%d %d",&n,&m);
    for(i=0;i<n+m;i++){
        scanf("%d",&opr1);
        if(a==1){
            scanf("%d",&opr2);
            if(opr2==1){
                scanf("%d %d",&w,&v);
                h.push({1,w,v,1000100,0});
            }
            else if(opr2==2){
                scanf("%d %d %d",&w,&v,&d);
                h.push({2,w,v,d,0});
            }
            else(opr2==3){
                scanf("%d %d %d %d",&w,&v,&d,%x);
                h2.push({3,w,v,d,x});
            }
        }
        else{
            while(1){
                if(h.empty()){
                    printf("0\n"); break;
                }
                temp = h.top();
                temp2 = h2.top();
                if(temp.type==2 && temp.day<=i) {h.pop();continue;}
                temp2



                h.pop();
                h2.pop();


            }
        }
    }
    return 0;
}
