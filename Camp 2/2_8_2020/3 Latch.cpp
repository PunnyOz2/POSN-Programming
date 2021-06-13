#include <bits/stdc++.h>
using namespace std;
long long a[1100][1100],h[1100][1100],ans[1100][1100];
struct A{
    long long h,posj,cou;
};
stack<A> q;
int main(){
    long long n,m,i,j,nownum,anss=0,cou;
    scanf("%lld %lld",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%lld",&a[i][j]);
        }
    }
    for(j=1;j<=m;j++){
        nownum=0;
        for(i=1;i<=n;i++){
            if(nownum==a[i][j]){
                h[i][j]=h[i-1][j]+1;
            }
            else{
                nownum=a[i][j];
                h[i][j]=1;
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(a[i][j]!=a[i][j-1]){
                while(!q.empty())q.pop();
            }
            cou=1;
            while(!q.empty() && q.top().h>=h[i][j]){
                cou+=q.top().cou;
                q.pop();
            }
            ans[i][j]=h[i][j]*cou;
            if(!q.empty())ans[i][j]+=ans[i][q.top().posj];
            anss+=ans[i][j];
            q.push({h[i][j],j,cou});
        }
        while(!q.empty())q.pop();
    }
    printf("%lld\n",anss);
}
/*
2 3
1 1 2
1 1 2

3 3
1 1 1
1 1 1
1 1 1
*/
