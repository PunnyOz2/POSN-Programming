/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<double,int> > q;
int a[300100];
double b[300100];
int main()
{
    int n,idx,idx2,m,i;
    double sum,Max=-10000000;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
        b[i]=a[i];
        a[i]+=a[i-1];
    }
    for(i=1;i<=n;i++){
        b[i]-=sum/n;
        b[i]+=b[i-1];
        printf("%llf ",b[i]);
    }
    q.push({0,0});
    for(i=m;i<=n;i++){
        if(i-m>0)q.push({-b[i-m],i-m});
        if(Max<b[i]+q.top().first){
            Max=b[i]+q.top().first;
            idx=q.top().second;
            idx2=i;
        }
    }
    printf("%d %d %lf\n",idx2,idx,Max);
    printf("%.1lf\n",(double)(a[idx2]-a[idx])/(idx2-idx));
    return 0;
}
/*
6 3
6 2 0 2 1 7
*/
