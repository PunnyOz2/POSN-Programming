/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int segmax[800100],arr[200100],arr2[200100],segmin[800100];
void build(int l,int r,int now){
    if(l==r){
        segmax[now]=arr[l];
        segmin[now]=arr[l];
        return;
    }
    int mid=(l+r)/2;
    build(l,mid,now*2);
    build(mid+1,r,now*2+1);
    segmax[now]=max(segmax[now*2],segmax[now*2+1]);
    segmin[now]=min(segmin[now*2],segmin[now*2+1]);
}
void update(int l,int r,int a,int c,int now){
    if(l>a||r<a)return;
    if(l==r){
        segmax[now]=c;
        segmin[now]=c;
        return;
    }
    int mid=(l+r)/2;
    update(l,mid,a,c,now*2);
    update(mid+1,r,a,c,now*2+1);
    segmax[now]=max(segmax[now*2],segmax[now*2+1]);
    segmin[now]=min(segmin[now*2],segmin[now*2+1]);
}
int query(int l,int r,int a,int b,int now,int mode){
    if(mode==1){
        if(l>b||r<a)return -1e9;
        if(a<=l && r<=b){
            return segmax[now];
        }
        int mid=(l+r)/2;
        return max(query(l,mid,a,b,now*2,mode),query(mid+1,r,a,b,now*2+1,mode));
    }
    if(mode==2){
        if(l>b||r<a)return 1e9;
        if(a<=l && r<=b){
            return segmin[now];
        }
        int mid=(l+r)/2;
        return min(query(l,mid,a,b,now*2,mode),query(mid+1,r,a,b,now*2+1,mode));
    }
}
int main()
{
    int n,q,com,i,a,b;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++){
        scanf("%d",&arr2[i]);
    }
    for(i=1;i<=n;i++){
        arr[arr2[i]]=i;
    }
    build(1,n,1);
    while(q--){
        scanf("%d %d %d",&com,&a,&b);
        if(a>b)swap(a,b);
        if(com==1){
            swap(arr2[a],arr2[b]);
            update(1,n,arr2[a],a,1);
            update(1,n,arr2[b],b,1);
        }
        if(com==2){
            if(query(1,n,a,b,1,1)-query(1,n,a,b,1,2)!=b-a){
                printf("NO\n");
            }
            else printf("YES\n");
        }
    }
    return 0;
}
