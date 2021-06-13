/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int fw[1020000];
struct A{
    int idx,h,v;
    bool operator<(const A&o)const{
        return idx<o.idx;
    }
};
vector<A> g;
int main()
{
    int n,m,i,j,idx,h,val,l,r,mid,sum,ch,st,w,o,low,ans=0;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%d %d %d %d",&st,&h,&w,&o);
        g.push_back({st,h,o});
        g.push_back({st+w,h,-1*o});
    }
    g.push_back({4000000,0,0});
    sort(g.begin(),g.end());
    for(i=0;i<g.size()-1;i++){
        idx=g[i].idx;
        h=g[i].h;
        val=g[i].v;
        for(j=1;j<=1000000;j+=(j&-j)){
            fw[j]+=val;
        }
        for(j=h+1;j<=1000000;j+=(j&-j)){
            fw[j]-=val;
        }
        while(g[i+1].idx==g[i].idx){
            i++;
            idx=g[i].idx;
            h=g[i].h;
            val=g[i].v;
            for(j=1;j<=1000000;j+=(j&-j)){
                fw[j]+=val;
            }
            for(j=h+1;j<=1000000;j+=(j&-j)){
                fw[j]-=val;
            }
        }
        l=1,r=1000000;
        while(l<r){
            mid=(l+r)/2;
            sum=0;
            ch=1;
            for(j=mid;j>0;j-=(j&-j)){
                sum+=fw[j];
            }
            if(sum>=m)l=mid+1;
            else r=mid;
        }
        low=l;
        l=1,r=1000000;
        while(l<r){
            mid=(l+r)/2;
            sum=0;
            ch=1;
            for(j=mid;j>0;j-=(j&-j)){
                sum+=fw[j];
            }
            if(sum>m)l=mid+1;
            else r=mid;
        }
        //printf("%d %d %d\n",low,l,idx);
        if(g[i+1].idx==4000000)ans+=(low-l);
        else ans+=(low-l)*(g[i+1].idx-g[i].idx);
    }
    printf("%d\n",ans);
    return 0;
}
/*
3 3
1 1 4 1
2 2 2 2
3 3 1 3
*/
