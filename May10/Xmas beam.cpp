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
deque<pair<int,int>> Max,Min;
pair<int,int> a[100100];
int main()
{
    int q,n,h,x,y,Ran,i,l,r,mid;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&h);
        Ran=1<<30;
        r=0;
        for(i=0;i<n;i++){
            scanf("%d %d",&a[i].x,&a[i].y);
            r=max(r,a[i].x);
        }
        sort(a,a+n);
        l=1,r=r+1;
        int mm=r;
        while(l<r){
                Ran=1<<30;
            mid=(l+r)/2;
            for(i=0;i<n;i++){
                x=a[i].x,y=a[i].y;
                while(!Max.empty() && Max.front().x<x-mid)Max.pop_front();
                while(!Min.empty() && Min.front().x<x-mid)Min.pop_front();
                while(!Max.empty() && Max.back().y<=y)Max.pop_back();
                while(!Min.empty() && Min.back().y>=y)Min.pop_back();
                Max.push_back({x,y}),Min.push_back({x,y});
                while(a[i].x==a[i+1].x){
                    i++;
                    x=a[i].x,y=a[i].y;
                    while(!Max.empty() && Max.front().x<x-mid)Max.pop_front();
                    while(!Min.empty() && Min.front().x<x-mid)Min.pop_front();
                    while(!Max.empty() && Max.back().y<=y)Max.pop_back();
                    while(!Min.empty() && Min.back().y>=y)Min.pop_back();
                    Max.push_back({x,y}),Min.push_back({x,y});
                }
                if(Max.front().y-Min.front().y>=h){
                    Ran=min(Ran,abs(Max.front().x-Min.front().x));
                }
            }
            if(Ran==1<<30)l=mid+1;
            else r=mid;
            while(!Max.empty())Max.pop_back();
            while(!Min.empty())Min.pop_back();
        }
        if(l==mm)printf("-1\n");
        else printf("%d\n",l);
    }
    return 0;
}
/*
2
5 10
1 3
3 7
4 5
5 13
8 2

4
4 3
1 13
3 12
6 9
7 25
*/
