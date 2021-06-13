#include<bits/stdc++.h>
using namespace std;
struct A{
    int x,y,idx;
};
bool cmpx(A a,A b){
    return a.x<b.x;
}
bool cmpy(A a,A b){
    return a.y<b.y;
}
A a[1000100];
int mark[1000100],p[1000050];
int fin(int i){
    if(p[i]==i)return i;
    return p[i]=fin(p[i]);
}
int main()
{
	int q,n,i,pu,pv;
	scanf("%d",&q);
	while(q--){
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d %d",&a[i].x,&a[i].y);
            a[i].idx=i;
            p[i]=i;
        }
        sort(a+1,a+n+1,cmpx);
        for(i=1;i<n;i++){
            while(i<n && a[i].x==a[i+1].x){
                pu=fin(a[i].idx);
                pv=fin(a[i+1].idx);
               // printf("%d %d\n",pu,pv);
                if(pu!=pv){
                    p[pv]=pu;
                }
                i++;
            }
        }
        sort(a+1,a+n+1,cmpy);
        for(i=1;i<n;i++){
            while(i<n && a[i].y==a[i+1].y){
                pu=fin(a[i].idx);
                pv=fin(a[i+1].idx);
               // printf("%d %d\n",pu,pv);
                if(pu!=pv){
                    p[pv]=pu;
                }
                i++;
            }
        }
        memset(mark,0,sizeof mark);
        int cou=0;
        for(i=1;i<=n;i++){
            if(mark[p[i]]==0)mark[p[i]]=1,cou++;
        }
        printf("        %d  \n",cou);
        if(cou%2==1)cou++;
        printf("%d\n",cou/2);
	}
    return 0;
}
/*
2
4
1 2
2 1
2 3
3 2
9
2 1
1 2
2 3
2 5
1 6
2 7
4 3
5 4
4 5
*/
