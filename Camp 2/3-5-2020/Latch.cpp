/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long h,posj,cou;
};
stack<A> q;
long long a[1010][1010],h[1010][1010],ans[1010][1010],anss;
int main()
{
    long long n,m,i,j,cou;
    scanf("%lld %lld",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%lld",&a[i][j]);
        }
    }
    for(j=1;j<=m;j++){
        for(i=n;i>=1;i--){
            if(a[i+1][j]==a[i][j])h[i][j]=h[i+1][j]+1;
            else h[i][j]=1;
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(a[i][j-1]!=a[i][j]){
                while(!q.empty())q.pop();
            }
            cou=1;
            while(!q.empty() && q.top().h>=h[i][j]){
                cou+=q.top().cou;
                q.pop();
            }
            ans[i][j]+=cou*h[i][j];
            if(!q.empty())ans[i][j]+=ans[i][q.top().posj];
            anss+=ans[i][j];
            q.push({h[i][j],j,cou});
        }
        while(!q.empty())q.pop();
    }
    printf("%lld\n",anss);
    return 0;
}
/*
2 3
1 1 2
1 1 2
*/
