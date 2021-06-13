/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> g[12];
int a[2000];
void play(int l,int r,int now){
    int mid=(l+r)/2;
    g[now].push_back(a[mid]);
    if(l!=r)
        play(l,mid-1,now+1),play(mid+1,r,now+1);
}
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=(1<<n)-1;i++){
        scanf("%d",&a[i]);
    }
    play(1,(1<<n)-1,1);
    for(i=1;i<=n;i++){
        for(auto x:g[i]){
            printf("%d ",x);
        }
        printf("\n");
    }
    return 0;
}
