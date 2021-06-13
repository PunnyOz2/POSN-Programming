/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int h,id;
    bool operator< (const A&o)const{
        return h<o.h;
    }
};
priority_queue<A> q;
int mark[100100];
int main()
{
    int n,Q,i,h,num,ans,id,Max=0,cou,ch=1;
    scanf("%d %d",&n,&Q);
    for(i=1;i<=n;i++){
        scanf("%d",&h);
        q.push({h,i});
    }
    for(i=1;i<=Q;i++){
        scanf("%d",&num);
        cou=0;
        while(1){
            if(q.empty())break;
            h=q.top().h,id=q.top().id;
            if(mark[id]!=i && mark[id]!=0)q.pop();
            else if(num<h){
                if(mark[id]==0)cou++;
                if(mark[id-1]==0&&id-1>=1)cou++;
                if(mark[id+1]==0&&id+1<=n)cou++;
                mark[id]=mark[id-1]=mark[id+1]=i;
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
3
1
4
6
7
3
5

5
4
6
2


*/
