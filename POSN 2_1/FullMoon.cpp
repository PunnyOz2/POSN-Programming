/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[100100],b[100100],c[100100],d[100100];
int main()
{
	int n,i,p,k,p2,k2,j,h;
	scanf("%d",&n);
	p=k=0;
	for(i=0;i<n;i++){
        scanf("%d",&h);
        if(h>0)a[p++]=h;
        else   b[k++]=h*-1;
	}
	p2=k2=0;
	for(i=0;i<n;i++){
        scanf("%d",&h);
        if(h>0)c[p2++]=h;
        else   d[k2++]=h*-1;
	}
	sort(a,a+p);
	sort(b,b+k);
	sort(c,c+p2);
	sort(d,d+k2);
	int cou=0;
	i=j=0;
	while(i<p && j<k2){
        if(a[i]<d[j])i++,j++,cou++;
        else if(a[i]>=d[j])j++;
	}
	i=j=0;
	while(i<k && j<p2){
        if(b[i]>c[j])i++,j++,cou++;
        else if(b[i]<=c[j])i++;
	}
    printf("%d",cou);
    return 0;
}
