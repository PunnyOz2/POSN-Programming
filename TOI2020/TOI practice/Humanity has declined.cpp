#include<bits/stdc++.h>
using namespace std;
int a[200100],ans[200100];
int mp[200100];
int main(){
    int n,k,q,l,i,r,cou=0;
    scanf("%d %d %d",&n,&k,&q);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    l=1;
    for(i=1;i<=n;i++){
        if(a[i]>k)continue;
        if(mp[a[i]]==0)cou++;
        mp[a[i]]++;
        while(cou==k){
            ans[l]=i;
            mp[a[l]]--;
            if(mp[a[l]]==0)cou--;
            l++;
        }
    }
    for(i=1;i<=n;i++)if(ans[i]==0)ans[i]=1<<30;
    while(q--){
        scanf("%d %d",&l,&r);
        if(r>=ans[l])printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
/*
10 3 5
1 2 3 1 2 7 8 2 3 1
1 5
4 8
4 9
8 10
7 8
*/
