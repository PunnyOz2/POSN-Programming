#include <bits/stdc++.h>
using namespace std;
long long a[100100],pos[100100],ans[100100];
int main(){
    long long n,m,i,anss=0;
    scanf("%lld %lld",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        pos[a[i]]=i;
    }
    anss+=pos[1]-1;
    m--;
    for(i=1;i<=n;i++){
        if(pos[i]>pos[i%n+1])   ans[i]=pos[i%n+1]+n-pos[i];
        else                    ans[i]=pos[i%n+1]-pos[i];
    }
    for(i=1;i<=n;i++)   ans[i]+=ans[i-1];
    printf("%lld\n",m/n*ans[n]+ans[m%n]+anss);
}
/*
4 6
4 2 1 3
*/
