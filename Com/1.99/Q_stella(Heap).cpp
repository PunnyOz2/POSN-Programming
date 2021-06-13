/*
    TASK: Stella
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long mp,hl,st,type;
    bool operator< (const A& o)const{
        if(mp!=o.mp) return mp < o.mp;
        else return st> o.st;
    }
};
priority_queue< A > h;
A temp;
int main()
{
    long long k,ans1=0,ans2=0,i,j,mp,hl;
    char opr,opr2;
    scanf("%lld",&k);
    for(i=1;i<=k;i++){
        scanf(" %c",&opr);
        if(opr=='c'){
            scanf(" %c",&opr2);
            if(opr2=='n'){
                scanf("%lld",&mp);
                h.push({mp,0,i,1});
            }
            else if(opr2=='r'){
                scanf("%lld %lld",&mp,&hl);
                h.push({mp,hl,i,2});
            }
        }
        else if(opr=='u'){
            while(1){
                if(h.empty()) break;
                temp = h.top(); h.pop();
                if(temp.type==1){
                    ans1+=temp.mp; break;
                }
                else if(temp.type==2){
                    long long cnt=(i-temp.st)/temp.hl;
                    if(cnt==0){
                        ans1+=temp.mp; break;
                    }
                    for(j=0;j<cnt;j++)
                        temp.mp/=2;
                    if(temp.mp>0){
                        temp.st += cnt*temp.hl;
                        h.push(temp);
                    }
                }
            }
        }
    }
    while(!h.empty()){
            temp = h.top();h.pop();
            if(temp.type==1) ans2++;
            else{
                long long cnt = (k-temp.st)/temp.hl;
                for(j=0;j<cnt;j++)
                    temp.mp/=2;
                if(temp.mp) ans2++;
            }
    }
    printf("%lld %lld",ans1,ans2);
    return 0;
}
