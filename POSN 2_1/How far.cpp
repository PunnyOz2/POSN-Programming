/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,id;
    bool operator<(const A&o)const{
        if(v!=o.v)return v<o.v;
        return id>o.id;
    }
};
A a[1000100];
int main()
{
	int n,i,Max;
	scanf("%d",&n);
	for(i=0;i<n;i++){
        scanf("%d",&a[i].v);
        a[i].id=i;
	}
	sort(a,a+n);
	Max=0;
	for(i=0;i<n;i++){
        Max=max(Max,abs(i-a[i].id));
        if(a[i+1].v!=a[i].v||i==n-1)printf("%d %d\n",a[i].v,Max),Max=0;
	}
    return 0;
}
/*
12
4 3 2 1 5 1 2 1 3 6 5 4
*/
