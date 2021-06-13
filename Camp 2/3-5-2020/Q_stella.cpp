/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long idx,mp,haf;
    bool operator<(const A&o)const {
        if(mp!=o.mp)return mp<o.mp;
        return idx>o.idx;
    }
};
priority_queue<A> q;
int main()
{
    long long Q,i=0,ans=0,cou,mp,haf,idx,temp;
    char c,type;
    scanf("%lld",&Q);
    while(Q--){
        i++;
        scanf(" %c",&c);
        if(c=='u'){
            while(1){
                if(q.empty())break;
                if((i-q.top().idx)/q.top().haf==0){
                    ans+=q.top().mp;
                    q.pop();
                    break;
                }
                cou=(i-q.top().idx)/q.top().haf;
                mp=q.top().mp;
                haf=q.top().haf;
                idx=q.top().idx;
                //printf(" %d %d %d\n",q.top().idx,q.top().mp,q.top().haf);
                q.pop();
                temp=cou;
                while(cou--){
                    mp/=2;
                }
                if(mp>0){
                    q.push({idx+haf*temp,mp,haf});
                }
                //printf("%d %d %d\n",idx+haf*temp,mp,haf);
            }
        }
        if(c=='c'){
            scanf(" %c",&type);
            if(type=='n'){
                scanf("%lld",&mp);
                q.push({i,mp,1000000});
            }
            else{
                scanf("%lld %lld",&mp,&haf);
                q.push({i,mp,haf});
            }
        }
    }
    long long anss=0;
    while(!q.empty()){
        if((i-q.top().idx)/q.top().haf==0)q.pop(),anss++;
        else{
            cou=(i-q.top().idx)/q.top().haf;
            mp=q.top().mp;
            haf=q.top().haf;
            q.pop();
            while(cou--){
                mp/=2;
            }
            if(mp>0)anss++;
        }
    }
    printf("%lld\n%lld\n",ans,anss);
    return 0;
}
/*
6
c n 100
c r 58 2
c n 40
u
u
u
*/
