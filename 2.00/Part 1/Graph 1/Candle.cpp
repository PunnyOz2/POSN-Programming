/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,id;
};
stack<A> b;
int a[2050][2050],mark[2050][2050];
int main()
{
    int i,j,m,n,sti,stj,cou=0,gg2,cou9,id;
    char gg[2050];
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf(" %s",gg);
        gg2=strlen(gg);
        for(j=1;j<=gg2+1;j++){
            a[i][j]=gg[j-1]-'0';
            if(a[i][j]==1){
                b.push({i,j,1});
            }
        }
    }
    while(!b.empty()){
        sti=b.top().i,stj=b.top().j,id=b.top().id,b.pop();
        if(mark[sti][stj]!=0)continue;
        mark[sti][stj]=1;
        for(i=sti-1;i<=sti+1;i++){
            for(j=stj-1;j<=stj+1;j++){
                if(a[i][j]==1 && mark[i][j]!=1){
                    b.push({i,j,2});
                }
            }
        }
        if(id==1)cou++;
    }
    printf("%d",cou);

    return 0;
}
/*
4 5
10011
00001
01100
10011
*/
