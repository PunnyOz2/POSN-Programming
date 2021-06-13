/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
pair<long long,long long> a[15100];
long long dis[15100];
int main()
{
    long long n,p,s,o,i,j,Min;
    scanf("%lld",&n);
    scanf("%lld %lld %lld",&p,&s,&o);
    for(i=1;i<=n;i++)
        scanf("%lld %lld",&a[i].x,&a[i].y),dis[i]=1e18;
    swap(a[s],a[1]);
    sort(a+2,a+n+1);
    long long pos,sum;
    if(p==2){
        for(i=1;i<n;i++){
            Min=1e18;
            for(j=i+1;j<=n;j++){
                dis[j]=min(dis[j],((a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y)));
                if(Min>dis[j])Min=dis[j],pos=j;
            }
            swap(dis[i+1],dis[pos]);
            swap(a[i+1],a[pos]);
        }
        sum=0;
        for(i=2;i<=n;i++)sum+=dis[i]*2+o;
        printf("%lld\n",sum);
    }
    if(p==1){
        for(i=1;i<n;i++){
            Min=1e18;
            for(j=i+1;j<=n;j++){
                dis[j]=min(dis[j],abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y));
                if(Min>dis[j])Min=dis[j],pos=j;
            }
            swap(dis[i+1],dis[pos]);
            swap(a[i+1],a[pos]);
        }
        sum=0;
        for(i=2;i<=n;i++)sum+=dis[i]*2+o;
        printf("%lld\n",sum);
    }
    if(p==3){
        for(i=1;i<n;i++){
            Min=1e18;
            for(j=i+1;j<=n;j++){
                dis[j]=min(dis[j],abs((a[i].x-a[j].x)*(a[i].x-a[j].x)*(a[i].x-a[j].x))+abs((a[i].y-a[j].y)*(a[i].y-a[j].y)*(a[i].y-a[j].y)));
                if(Min>dis[j])Min=dis[j],pos=j;
            }
            swap(dis[i+1],dis[pos]);
            swap(a[i+1],a[pos]);
        }
        sum=0;
        for(i=2;i<=n;i++)sum+=dis[i]*2+o;
        printf("%lld\n",sum);
    }
    return 0;
}
/*
2 1 1 0
1 1 2 2

3
2 3 1
1 4
2 6
3 3
*/
