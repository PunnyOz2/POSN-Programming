/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int a,b;
    bool operator<(const A&o)const{
        if(a!=o.a)return a<o.a;
        return b<o.b;
    }
};
A a[1000100],b[1000100];
int Maxx[1000100];
int main()
{
    int n,i,num,Max,Min,idx;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&num);
        a[i].a=num;
        a[i].b=i;
        b[i]=a[i];
    }
    sort(b+1,b+1+n);
    Max=0,Min=1<<30,idx=1;
    for(i=1;i<=n;i++){
        Max=max(Max,b[i].b);
        Min=min(Min,b[i].b);
        if(b[i].a!=b[i+1].a){
            Maxx[i]=max(abs(idx-Max),max(abs(idx-Min),max(abs(i-Min),abs(i-Max))));
            Max=0,Min=1<<30;
            idx=i+1;
        }
    }
    for(i=1;i<=n;i++){
        if(Maxx[i]!=0){
            printf("%d %d\n",b[i].a,Maxx[i]);
        }
    }
    return 0;
}
/*
12
4 3 2 1 5 1 2 1 3 6 5 4
*/
