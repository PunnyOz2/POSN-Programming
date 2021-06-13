#include<bits/stdc++.h>
using namespace std;
int n,m;
struct A{
    int i,w,wlast;
    bool operator<(const A&o)const{
        if(i!=o.i)return i<o.i;
        return w>o.w;
    }
};
priority_queue<A> q;
pair<int,int> a[2010][4010];
int main(){
    int n,m,i,j,sti,stj,Min,w,k,kk,wlast,top;
    char posi,posj;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d %c %d %c",&sti,&posi,&stj,&posj);
        a[i][0]={sti,stj};
        for(j=1;j<=m*2;j++){
            if(posi=='L')sti--;
            else sti++;
            if(posj=='L')stj--;
            else stj++;
            if(sti<0)sti=1,posi='R';
            if(stj>m)stj=m-1,posj='L';
            if(sti-stj==1 && posi=='R' && posj=='L')stj++,sti--,posi='L',posj='R';
            else if(sti-stj==2)sti-=2,stj+=2,posi='L',posj='R';
            a[i][j]={sti,stj};
        }
    }
    Min=1<<30;
    for(j=1;j<=m;j++){
        q.push({0,0,0});
        top=-1;
        while(!q.empty()){
            i=q.top().i;
            w=q.top().w;
            wlast=q.top().wlast;
            q.pop();
            if(top>=i)continue;
            if(wlast>=m*2)top=i;
            if(i==n){Min=min(Min,w);break;}
            if(i==0 || (a[i][(w+1)%(m*2)].first<j && a[i][(w+1)%(m*2)].second>j)){
                if(wlast+1<=m*2)
                    q.push({i,w+1,wlast+1});
            }
            if(a[i+1][(w+1)%(m*2)].first<j && a[i+1][(w+1)%(m*2)].second>j){
                q.push({i+1,w+1,0});
            }
        }
        while(!q.empty())q.pop();
    }
    printf("%d\n",Min+1);
    return 0;
}
/*
5 7
4 R 4 L
1 L 6 R
1 R 7 R
2 R 7 R
1 R 3 R
*/
