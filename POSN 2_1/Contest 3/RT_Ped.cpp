/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char a[1200][20];
int mark[1200];
int main()
{
	int n,q,idx=0,cou=0,i,r,nub=0;
	scanf("%d %d",&n,&q);
	for(i=1;i<=n;i++)
        scanf(" %s",a[i]);
    int q1=q;
        i=1;
        cou=0;
    while(q--){
        scanf("%d",&r);
        nub=0;
        while(nub<r){
            i++;
            i%=(n);
            if(i==0)i=n;
            if(mark[i]!=0)continue;
            nub++;
            //printf("%d ",i);
        }
        printf("%s\n",a[i]),mark[i]=1,cou++;
        while(mark[i]!=0 &&cou!=n){
            i++;
            i%=(n);
            if(i==0)i=n;
        }
    }
    return 0;
}
/*
5 5
PI
HA
PED
BBQ
BIN

*/
