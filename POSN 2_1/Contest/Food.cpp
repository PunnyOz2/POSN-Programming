/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int n,m,j,mark[10],ans[10],markn[10];
void permu(int state){
    int i;
    if(state==n){
        for(i=0;i<m;i++){
            if(ans[0]==mark[i])return;
        }
        for(i=0;i<n;i++){
            printf("%d ",ans[i]);
        }
        printf("\n");
        return;
    }
    for(i=1;i<=n;i++){
        if(markn[i]!=1){
        //printf("%d %d\n",i,state);
            ans[state]=i;
            markn[i]=1;
            permu(state+1);
            markn[i]=0;
        }
    }
}
int main()
{
    int a,i;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++){
        scanf("%d",&a);
        mark[i]=a;
	}
	permu(0);
    return 0;
}
/*
4
3
1 2 3
*/
