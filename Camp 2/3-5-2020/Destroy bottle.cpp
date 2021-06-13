/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int num,idx;
    bool operator<(const A&o)const{
        return num<o.num;
    }
};
priority_queue<A> q;
int mark[100100];
int main()
{
    int n,Q,i,num,left,now,mid,l,r,cou;
    scanf("%d %d",&n,&Q);
    for(i=1;i<=n;i++){
        scanf("%d",&num);
        q.push({num,i});
    }
    i=0;
    while(Q--){
        i++;
        cou=0;
        scanf("%d",&num);
        while(!q.empty()){
            if(mark[q.top().idx]!=i && mark[q.top().idx]!=0)q.pop();
            else if(q.top().num>num){
                if(mark[q.top().idx]==0)mark[q.top().idx]=i,cou++;
                if(q.top().idx+1<=n && mark[q.top().idx+1]==0)mark[q.top().idx+1]=i,cou++;
                if(q.top().idx-1>=1 && mark[q.top().idx-1]==0)mark[q.top().idx-1]=i,cou++;
                q.pop();
            }
            else break;
        }
        printf("%d\n",cou);
    }
    return 0;
}
/*
7 4
3 1 4 6 7 3 5
5
*/
