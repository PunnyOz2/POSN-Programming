/*
    TASK: Tree
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v;
    bool operator<(const A&o)const{
        if(u!=o.u) return u<o.u;
        return v<o.v;
    }
};
A a[100100],b[100100];
int main()
{
	int n,q=5,i;
	while(q--){
        int ch=0;
        scanf("%d",&n);
        for(i=0;i<n-1;i++){
            scanf("%d %d",&a[i].u,&a[i].v);
            if(a[i].u>a[i].v)swap(a[i].u,a[i].v);
        }
        for(i=0;i<n-1;i++){
            scanf("%d %d",&b[i].u,&b[i].v);
            if(b[i].u>b[i].v)swap(b[i].u,b[i].v);
        }
        sort(a,a+n-1);
        sort(b,b+n-1);
        for(i=0;i<n-1;i++){
            if(a[i].u!=b[i].u ||a[i].v!=b[i].v){printf("N"),ch=1;break;}
        }
        if(ch==0){
            printf("Y");
        }
	}
    return 0;
}
/*
9
2 4 9 4 6 4 1 4 1 5 3 5 7 5 7 8
1 4 4 9 1 5 6 4 3 5 7 5 7 8 2 4
*/
