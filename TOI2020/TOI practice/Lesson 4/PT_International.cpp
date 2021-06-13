#include<bits/stdc++.h>
using namespace std;
struct A{
    int pos,id;
    bool operator<(const A&o)const{
        return pos<o.pos;
    }
};
int need[50100];
int mark[50100];
A a[50100];
unordered_map<int,int> mp;
int main(){
    int q,i,n,l,cou=0,now,Min;
    scanf("%d",&q);
    while(q--){
        Min=1<<30;
        cou=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d %d",&a[i].pos,&a[i].id);
            if(mp[a[i].id]==0)mp[a[i].id]= ++cou;
        }
        sort(a+1,a+n+1);
        l=0;
        now=0;
        for(i=1;i<=n;i++){
            if(mark[mp[a[i].id]]==0)now++;
            mark[mp[a[i].id]]++;
            while(now==cou){
                need[l]=i;
                if(mark[mp[a[l].id]]==1)now--;
                mark[mp[a[l].id]]--;
                l++;
            }
        }
        for(i=1;i<=n;i++)if(need[i]==0)need[i]=1<<30;
        for(i=1;i<=n;i++){
            if(need[i]==1<<30)continue;
            Min=min(Min,a[need[i]].pos-a[i].pos);
        }
        printf("%d\n",Min+1);
        memset(need,0,sizeof need);
        memset(mark,0,sizeof mark);
        mp.clear();
    }
    return 0;
}
/*
3
6
20 1
15 9
16 1
5 1
12 5
10 1
6
5 1
10 1
12 5
15 9
16 1
20 1
*/
