#include <bits/stdc++.h>
using namespace std;
struct A{
    int i,j;
    bool operator<(const A&o)const{
        if(i!=o.i) return i>o.i;
        return j<o.j;
    }
};
struct B{
    int i,j;
    bool operator<(const B&o)const{
        if(i!=o.i)return i<o.i;
        return j<o.j;
    }
};
A a[1000100];
vector<B>ans;
int main(){
    int n,i,Max;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d %d",&a[i].i,&a[i].j);
    }
    sort(a+1,a+n+1);
    Max=-1<<30;
    for(i=1;i<=n;i++){
        if(a[i].j>=Max){
            Max=a[i].j;
            ans.push_back({a[i].i,a[i].j});
        }
        //else if(a[i].i==a[1].i && a[i].j==Max)ans.push_back({a[i].i,a[i].j});
    }
    sort(ans.begin(),ans.end());
    for(auto x:ans){
        printf("%d %d\n",x.i,x.j);
    }
}
/*
5
9 1
8 2
7 3
6 4
5 5

7
5 5 5 6 5 4 5 1 5 5
4 7
4 6
*/
