/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[100100],idx[100100];
int fw[100100];
void add(int u,int p){
    int idx=u;
    while(idx<=100003){
        fw[idx]+=p;
        idx+=(idx&-idx);
    }
}
int query(int u){
    int sum=0;
    while(u>0){
        sum+=fw[u];
        u-=(u&-u);
    }
    return sum;
}
int main()
{
	int n,i,b;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
        scanf("%d",&b);
        idx[b]=i;
	}
	for(i=1;i<=n;i++){
        add(i,1);
	}
	int j=0,k=n;
	for(i=1;i<=n;i++){
        if(i%2==1){
            printf("%d\n",query(idx[++j]-1));
            add(idx[j],-1);
        }
        else{
            printf("%d\n",n-query(idx[k]-1)-i);
            add(idx[k--],-1);
        }
	}
    return 0;
}
/*
6
6
5
4
3
2
1
*/
