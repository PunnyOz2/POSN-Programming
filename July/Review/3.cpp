/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct B{
    int id,l,r;
    bool operator<(const B&o)const{
        if(l!=o.l)return l<o.l;
        return r<o.r;
    }
};
vector<B> s;
int a[100100];
int main()
{
    int q,n,i,l,r,last=0,a1,a2,lastg=1,ch1,ch2,Max,Min;
    scanf("%d",&q);
    while(q--){
        ch1=0,ch2=0,Max=0,Min=3;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d %d",&l,&r);
            s.push_back({i,l,r});
        }
        sort(s.begin(),s.end());
        a1=0,a2=0,lastg=1,last=0;
        for(auto x:s){
            if(x.l<=last)a[x.id]=lastg;
            else lastg=3-lastg,a[x.id]=lastg;
            last=max(last,x.r);
        }
        for(i=0;i<n;i++)Max=max(Max,a[i]),Min=min(Min,a[i]);
        if(Max==2 && Min==1)for(i=0;i<n;i++)printf("%d ",a[i]);
        else printf("-1");
        printf("\n");
        s.clear();
    }

    return 0;
}
/*
3

2
5 5
2 3
*/
