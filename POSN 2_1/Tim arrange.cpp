/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int st,en;
    bool operator< (const A&o)const{
        if(en!=o.en)return en<o.en;
        else return st<o.st;
    }
};
A a[100100];
int main()
{
	int n,i,last,cou;
	scanf("%d",&n);
	for(i=0;i<n;i++){
        scanf("%d %d",&a[i].st,&a[i].en);
	}
	sort(a,a+n);
	last=0;
	for(i=0,cou=0;i<n;i++){
        if(a[i].st<last)continue;
        else cou++,last=a[i].en;
	}
	printf("%d",cou);
    return 0;
}
