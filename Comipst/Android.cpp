/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long val,idx,id;
};
queue<A>q;
long long idx[2100],a[1010],sum,temp;
int main()
{
    long long n,Q,m,st=0,i,x;
    scanf("%lld %lld %lld",&n,&Q,&m);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    while(Q--){
        st++;
        scanf("%lld",&x);
        if(idx[x]==0){
            while(!q.empty() && sum+a[x]>m){
                //printf("A   %lld %lld %lld\n",q.front().val,idx[q.front().idx],q.front().id);
                if(idx[q.front().idx]==q.front().id){
                  //  printf("deleted\n");
                    sum-=q.front().val;
                    //temp=q.front().id;
                    idx[q.front().idx]=0;
                }
                q.pop();
            }
            idx[x]=st;
            sum+=a[x];
            q.push({a[x],x,st});
        }
        else{
            idx[x]=st;
            q.push({a[x],x,st});
        }
//            printf("  %lld\n",sum);
    }
    printf("%lld\n",m-sum);
    return 0;
}
/*
4 7 75
10
20
30
40
1
2
3
1
3
4
2
*/
