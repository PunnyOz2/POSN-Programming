/*
    TASK: AP_road
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
PII want[300100],edge[300100];
int p[300100];
int fin(int i){
    if(p[i]==i) return i;
    return p[i]=fin(p[i]);
}
int main()
{
    int q,i,v,e,m,j,l,r,mid,ch;
    scanf("%d",&q);
    for(i=1;i<=q;i++){
        scanf("%d %d %d",&v,&e,&m);
        for(j=1;j<=m;j++)
            scanf("%d %d",&want[j].first,&want[j].second);
        for(j=1;j<=e;j++)
            scanf("%d %d",&edge[j].first,&edge[j].second);
            l=1,r=e+1;
            while(l<r){
                mid=(l+r)/2;
                for(j=1;j<=v;j++) p[j]=j;
                for(j=1;j<=mid;j++) p[fin(edge[j].first)]=fin(edge[j].second);
                for(j=1,ch=1;j<=m;j++){
                    if(fin(want[j].first)!=fin(want[j].second)){
                        ch=0; break;
                    }
                }
                if(ch) r=mid;
                else l=mid+1;
            }

    printf("C#%d: ",i);
    if(l<=e) printf("%d\n",l);
    else printf("-1\n");
    }

    return 0;
}
/*
1
5 5 5
1 2
1 3
3 2
4 5
2 5
1 5
2 3
1 4
1 3
2 5
*/
