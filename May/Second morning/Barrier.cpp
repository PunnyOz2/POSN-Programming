/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
deque<pair<int,int>> Ma;
deque<pair<int,int>> Mi;
int a[6000100];
int main()
{
    int n,m,ans=0,ansl,i,maxx = 0,len = 0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)scanf("%d",&a[i]),a[i]+=a[i-1];
//    Ma.push_back({0,0});
    Mi.push_back({0,0});
    for(i=1;i<=n;i++){
        while(!Mi.empty() && i-Mi.front().second>m) Mi.pop_front();
        while(!Mi.empty() && Mi.back().first>=a[i]) Mi.pop_back();
        Mi.push_back({a[i],i});
        if(maxx<a[i]-Mi.front().first){
            maxx = a[i]-Mi.front().first;
            len = i-Mi.front().second;
        }else if(maxx == a[i]-Mi.front().first){
            len = min(len,i-Mi.front().second);
        }
//        while(!Ma.empty() && i-Ma.front().second>=m)Ma.pop_front();
//        while(!Mi.empty() && i-Mi.front().second>m)Mi.pop_front();
//        while(!Ma.empty() && Ma.back().first<a[i])Ma.pop_back();
//        Ma.push_back({a[i],i});
//        //printf("%d\n",Ma.front().first-Mi.front().first);
//        if(ans<Ma.front().first-Mi.front().first){
//            ans=Ma.front().first-Mi.front().first;
//            ansl=Ma.front().second-Mi.front().second;
//        }
//        else if(ans==Ma.front().first-Mi.front().first && ansl>Ma.front().second-Mi.front().second+1){
//            ansl=Ma.front().second-Mi.front().second;
//        }
//        while(!Mi.empty() && Mi.back().first>a[i])Mi.pop_back();
//        Mi.push_back({a[i],i});
    }
    printf("%d\n%d\n",maxx,len);
//    if(ans==0)printf("0\n0\n");
//    else printf("%d %d\n",ans,ansl);
    return 0;
}
/*
7 4
3
2
5
1
4
-7
10
*/
