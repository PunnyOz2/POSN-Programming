/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[25000];
struct A{
    int b;
    bool operator<(const A&o)const{
        return b<o.b;
    }
};
priority_queue<A> q;
int main()
{
    int n,m,temp,sum,ans=0,i;
    char last='A',now;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(i=1;i<=n;i++){
        scanf("%c",&now);
        if(i!=1 && now!=last){
            //printf("%d %c %c\n",i,last,now);
            sum=0;
            temp=0;
            while(!q.empty() && temp<m)sum+=q.top().b,q.pop(),temp++;
            while(!q.empty())q.pop();
            ans+=sum;
            printf("%d\n",ans);
        }
        q.push({a[i]});
        last=now;
    }
    printf("%d\n",ans);
    return 0;
}
