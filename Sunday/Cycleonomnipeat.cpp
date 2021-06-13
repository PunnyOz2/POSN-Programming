/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> mp;
int a[100100];
int main()
{
    int q,n,i,num,ch,now,nownum;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            mp[a[i]]++;
        }
        sort(a,a+n);
        ch=1;
        sort(a,a+n);
        nownum=a[0];
        for(i=1;i<n;i++){
            if(i==n-1){
                if(nownum+1==a[i] && mp[nownum]>=1);
                else ch=0;
            }
            if(a[i]-1==nownum && a[i]>mp[nownum]){
                mp[a[i]]++;
            }
            else ch=0;
        }
        if(ch==1){
            printf("YES\n");
        }
        else printf("NO\n");
        mp.clear();
    }
    return 0;
}
/*
3
4
1 2 3 2
6
1 1 2 2 2 3
6
2 4 1 1 2 2
*/
