/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int p,h,w;
    bool operator<(const A&o)const{
        return p<o.p;
    }
};
vector<A> g;
int fw[1000100];
int main()
{
	int n,q,cou,ans=0,i,si,h,w,o,ep,j,mid,sum;
	scanf("%d %d",&n,&q);
	for(i=0;i<n;i++){
        scanf("%d %d %d %d",&si,&h,&w,&o);
        g.push_back({si,h,o});
        g.push_back({si+w,h,-1*o});
	}
	sort(g.begin(),g.end());
	for(i=0;i<g.size()-1;i++){
        ep=g[i].p  ,h=g[i].h   ,w=g[i].w;
        for(j=1;j<=1000000;j+=(j&-j)){
            fw[j]+=w;
        }
        for(j=h+1;j<=1000000;j+=(j&-j)){
            fw[j]-=w;
        }
        while(g[i+1].p==ep){
            i++;
            ep=g[i].p  ,h=g[i].h   ,w=g[i].w;
            for(j=1;j<=1000000;j+=(j&-j)){
                fw[j]+=w;
            }
            for(j=h+1;j<=1000000;j+=(j&-j)){
                fw[j]-=w;
            }
        }
        cou=0;
        int l=1 , r=1000000;
        while(l<r){
            mid=(l+r)/2;
            sum=0;
            for(j=mid;j>0;j-=(j&-j)){
                sum+=fw[j];
            }
            if(sum>q) l=mid+1;
            else r=mid;
        }
        int low=l;
        l=1 , r=1000000;
        while(l<r){
            mid=(l+r)/2;
            sum=0;
            for(j=mid;j>0;j-=(j&-j)){
                sum+=fw[j];
            }
            if(sum>=q) l=mid+1;
            else r=mid;
        }
        ans+=((l-low)*(g[i+1].p-ep));
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
