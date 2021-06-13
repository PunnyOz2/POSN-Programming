/*
    TASK: MagicHat
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int pow,id;
    bool operator< (const A&o)const{
        if(pow!=o.pow) return pow<o.pow;
        return id<o.id;
    }
};
A a[100100];
int main()
{
    int N,Q,d,f,sum,i,j,l,r,ch,mid,Max=0;
    scanf("%d %d",&N,&Q);
    sum=0;
    for(i=1;i<=N;i++){
        scanf("%d",&d);
        sum+=d;
        a[i].id=i;
        a[i].pow=sum;
    }
    sort(a+1,a+N+1);
    for(i=1;i<=N;i++){
        if(Max<a[i].id)Max=a[i].id;
        a[i].id=Max;
    }
    while(Q--){
        scanf("%d",&f);
        l=0,r=N;
        while(l<r){
            mid=(l+r+1)/2;
            if(a[mid].pow>f)r=mid-1;
            else l=mid;
        }
        printf("%d\n",a[l].id);
    }

    return 0;
}
/*
5 3
10 20 -10 30 60
31
52
9

6 3
3 1 1 -3 -2 3
2 1 3
*/
