/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int st,en;
    bool operator<(const A&o)const{
        if(en!=o.en)return en<o.en;
        return st<o.st;
    }
};
A a[100005];
int main()
{
    int ans=0,la=0,i,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d %d",&a[i].st,&a[i].en);
    }
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++){
        if(a[i].st<la)continue;
        ans++;
        la=a[i].en;
    }
    printf("%d",ans);
    return 0;
}
/*
7
0 2 3 6 7 10 0 4 5 7 8 10 6 8
*/
