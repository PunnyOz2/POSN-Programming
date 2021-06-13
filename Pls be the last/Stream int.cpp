/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int fw[1000100];
struct A{
    int val,en;
    bool operator<(const A&o)const{
        return en>o.en;
    }
};
priority_queue<A> q;
void update(int a,int b){
    while(a<1000003){
        fw[a]+=b;
        a+=(a&-a);
    }
}
int query(int a){
    int sum=0;
    while(a>0){
        sum+=fw[a];
        a-=(a&-a);
    }
    return sum;
}
int main()
{
    int Q,com,l,r,i,en,opr,val,k,mid;
    scanf("%d",&Q);
    while(Q--){
        scanf("%d",&com);
        for(i=1;i<=com;i++){
            scanf("%d",&opr);
            if(opr==1){
                scanf("%d %d",&val,&en);
                update(val,1);
                q.push({val,en});
            }
            else{
                scanf("%d",&k);
                l=1,r=1000001;
                while(l<r){
                    mid=(l+r)/2;
                    //printf("%d\n",mid);
                    if(query(mid)>=k)r=mid;
                    else l=mid+1;
                }
                if(l==1000001)printf("-1\n");
                else printf("%d\n",l);
            }
            while(!q.empty() && q.top().en<=i){
                update(q.top().val,-1);
                q.pop();
            }
        }
    }
    return 0;
}
/*
1
11
1 10 7
1 9 10
2 2
1 2 5
2 1
2 1
1 2 10
1 1 9
1 3 10
2 3
2 3
*/
