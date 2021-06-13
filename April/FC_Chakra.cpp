/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,w;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
priority_queue<A> h;
int di[4]={1,-1,0,0},dj[4]={0,0,1,-1};
int a[1200][1200];
int mark[1200][1200];
int main()
{
	int n,i,j,sti,stj,eni,enj,w,k;
	scanf("%d",&n);
	int ch=0;
	for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
            if(ch==0 && a[i][j]==0)sti=i,stj=j,ch=1;
            else if(ch==1 && a[i][j]==0)eni=i,enj=j;
        }
	}
    h.push({sti,stj,0});
    while(!h.empty()){
        i=h.top().i,j=h.top().j,w=h.top().w,h.pop();
        if(i==eni&&j==enj){printf("%d\n",w);break;}
        for(k=0;k<4;k++){
            if(i+di[k]<n && i+di[k]>=0 && j+dj[k]<n && j+dj[k]>=0 && mark[i+di[k]][j+dj[k]]!=1)mark[i+di[k]][j+dj[k]]=1,h.push({i+di[k],j+dj[k],max(a[i+di[k]][j+dj[k]],w)});
        }
    }
    return 0;
}
/*
5
1 1 1 0 1
3 1 1 1 1
0 3 4 3 2
1 1 1 4 1
1 4 2 2 2
*/
