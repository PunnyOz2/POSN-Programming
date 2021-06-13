/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v;
    bool operator<(const A&o)const{
        if(u!=o.u) return u>o.u;
        return v<o.v;
    }
};
struct B{
    int u,v;
    bool operator<(const B&o)const{
        if(u!=o.u) return u<o.u;
        return v<o.v;
    }
};
A a[1000100];
B b[1000100];
int mark[1000100];
int main()
{
	int n,i,Max=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
        scanf("%d %d",&a[i].u,&a[i].v);
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++){
        if(a[i].v<Max)mark[i]=1;
        else Max=a[i].v;
	}
	int p=0;
	for(i=n;i>=1;i--){
        if(mark[i]!=1){
            b[p].u=a[i].u;
            b[p].v=a[i].v;
            p++;
        }
	}
	sort(b,b+p);
	for(i=0;i<p;i++){
        printf("%d %d\n",b[i].u,b[i].v);
	}
    return 0;
}
/*
5
9 1
8 2
7 3
6 4
5 5
*/
