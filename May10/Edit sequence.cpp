/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int arr[100100],l[100100],r[100100];
pair<int,int> sm[400100];
void update(int l,int r,int idx,int now,int val){
    if(l>idx||r<idx)return ;
    if(l==r){
        sm[now]={val,val};return;
    }
    int mid=(l+r)/2;
    update(l,mid,idx,now*2,val),update(mid+1,r,idx,now*2+1,val);
    sm[now].first=min(sm[now*2].first,sm[now*2+1].first);
    sm[now].second=max(sm[now*2].second,sm[now*2+1].second);
}
pair<int,int> query(int l,int r,int ll,int rr,int now){
    if(!l)++l;
    if(l>rr||r<ll||l>r)return {1e9,0};
    if(l>=ll&&r<=rr)return sm[now];
    int mid=(l+r)/2;
    pair<int,int> a=query(l,mid,ll,rr,now*2),b=query(mid+1,r,ll,rr,now*2+1);
    return {min(a.first,b.first),max(a.second,b.second)};
}
int main()
{
    int n,i,cnt,ma=-1;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&arr[i]);
        update(1,n,arr[i],1,i);
    }
    cnt=0;
    arr[n+1]=n+1;
    for(i=1;i<=n;i++){
        l[++cnt]=i;
        while(arr[i+1]>arr[i])i++;
        r[cnt]=i;
    }
    r[cnt]=n;
    for(i=1;i<=cnt;i++){
        if(i-1>0){
            int sum=0;
            if(arr[l[i]]>arr[l[i]-2])sum=r[i-1]-l[i-1]+1;
            if(arr[r[i-1]]<arr[l[i]+1] && arr[r[i-1]]>arr[l[i]])sum+=r[i]-l[i]+1;
            ma=max(ma,sum);
            pair<int,int>a=query(1,n,arr[l[i]-1],arr[l[i]+1],1);
            pair<int,int>b=query(1,n,arr[l[i]-2],arr[l[i]],1);
            if(min(a.first,b.first)<l[i-1])ma=max(ma,r[i]+r[i-1]-l[i]-l[i-1]+2);
            if(max(a.second,b.second)>r[i])ma=max(ma,r[i]+r[i-1]-l[i]-l[i-1]+2);
        }
        if(i-1>0 && i+1<=cnt){
            int sum=r[i]-l[i]+1;
            if((arr[r[i]+1]>arr[l[i]-2]||l[i]-2<l[i-1])&&arr[r[i]+1]<arr[l[i]]) sum+=r[i-1]-l[i-1]+1;
            if(arr[l[i]-1]>arr[r[i]]&&(arr[l[i]-1]<arr[r[i]+2]||r[i]+2>r[i+1])) sum+=r[i+1]-l[i+1]+1;
            ma=max(ma,sum);
        }
        if(arr[l[i]]!=1&&l[i]!=1)ma=max(ma,r[i]-l[i]+2);
        if(arr[l[i]]!=n&&l[i]!=n)ma=max(ma,r[i]-l[i]+2);
    }
    printf("%d\n",ma);
    return 0;
}
/*
8
1 3 2 4 6 5 7 8
*/
