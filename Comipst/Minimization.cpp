/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[300100],mark[300100],b[300100];
struct A{
    int val,i,j;
    bool operator<(const A&o)const{
        return val>o.val;
    }
};
priority_queue<A>q;
int main()
{
    int n,k,ans=0,i,j;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    for(i=1;i<n;i++){
        q.push({abs(a[i]-a[i-1]),i,i-1});
    }
    j=n-k;
    int left=n-k*2;
    while(!q.empty() && j--){
        //printf("%d\n",q.top().val);
        if(left>0 && (mark[q.top().i]==1 || mark[q.top().j]==1)){
            left--;
            mark[q.top().i]=1;
            mark[q.top().j]=1;
            ans+=q.top().val;
            q.pop();
            continue;
        }
        if(mark[q.top().i]==0 && mark[q.top().j]==0){
            ans+=q.top().val;
            mark[q.top().i]=1;
            mark[q.top().j]=1;
            q.pop();
        }
    }
    while(!q.empty())q.pop();
    j=0;
    for(i=0;i<n;i++){
        if(mark[i]==0)b[j++]=a[i];
    }
    for(i=1;i<j;i++){
        q.push({abs(b[i]-b[i-1]),i,i-1});
    }
    while(!q.empty()){
        ans+=q.top().val;
        q.pop();
    }
//    if(j!=0){
//        ans+=abs(a[n-1]-a[n-2]);
//        for(i=2;i<n;i+=2){
//            q.push(-abs(a[i]-a[i-1]));
//        }
//        while(!q.empty() && j--){
//            ans+=q.top()*-1;
//            q.pop();
//        }
//    }
    printf("%d\n",ans);
    return 0;
}
/*
5 2
3 -5 3 -5 3
*/
