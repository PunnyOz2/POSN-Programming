/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[200100];
int bar[200100];
int bar2[200100];
struct A{
    int i,h;
    bool operator<(const A&o)const{
        if(h!=o.h)return h<o.h;
        return i>o.i;
    }
};
A b[1000100];
int main()
{
	int h,n,k,Max=-1,i,check,ii;
	scanf("%d %d %d",&h,&n,&k);
	for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        bar[i]=i;
        if(a[i]>Max)ii=i,Max=a[i];
	}
	for(i=0;i<k;i++){
        scanf("%d %d",&b[i].i,&b[i].h);
	}
	sort(b,b+k);
	for(i=0;i<k;i++){
        swap(bar[b[i].i],bar[b[i].i+1]);
	}
	for(i=1;i<=n;i++){
        bar2[bar[i]]=i;
        bar[i]=i;
	}
	scanf("%d",&check);
	if(Max==a[bar2[check]]){printf("%d\nNO\n",Max);return 0;}
	Max=a[bar2[check]];
	int ch=0,j;
	for(i=0;i<k;i++){
        if(b[i].i+2<=n){
                if(bar2[check]==bar[b[i].i+1] && Max<a[bar2[bar[b[i].i+2]]])Max=a[bar2[bar[b[i].i+2]]],ch=1;
                else if(bar2[check]==bar[b[i].i+2] && bar2[j]==check && Max<a[bar2[bar[b[i].i+1]]])Max=a[bar2[bar[b[i].i+1]]],ch=1;
            }
            if(bar2[check]==bar[b[i].i+1] && Max<a[bar2[bar[b[i].i]]])Max=a[bar2[bar[b[i].i]]],ch=1;
            else if(bar2[check]==bar[b[i].i] && Max<a[bar2[bar[b[i].i+1]]])Max=a[bar2[bar[b[i].i+1]]],ch=1;
            if(b[i].i-1>0){
                if(bar2[check]==bar[b[i].i-1] && Max<a[bar2[bar[b[i].i]]])Max=a[bar2[bar[b[i].i]]],ch=1;
                else if(bar2[check]==bar[b[i].i] && Max<a[bar2[bar[b[i].i-1]]])Max=a[bar2[bar[b[i].i-1]]],ch=1;
            }
        swap(bar[b[i].i],bar[b[i].i+1]);
            if(b[i].i+2<=n){
                if(bar2[check]==bar[b[i].i+1] && Max<a[bar2[bar[b[i].i+2]]])Max=a[bar2[bar[b[i].i+2]]],ch=1;
                else if(bar2[check]==bar[b[i].i+2] && bar2[j]==check && Max<a[bar2[bar[b[i].i+1]]])Max=a[bar2[bar[b[i].i+1]]],ch=1;
            }
            if(bar2[check]==bar[b[i].i+1] && Max<a[bar2[bar[b[i].i]]])Max=a[bar2[bar[b[i].i]]],ch=1;
            else if(bar2[check]==bar[b[i].i] && Max<a[bar2[bar[b[i].i+1]]])Max=a[bar2[bar[b[i].i+1]]],ch=1;
            if(b[i].i-1>0){
                if(bar2[check]==bar[b[i].i-1] && Max<a[bar2[bar[b[i].i]]])Max=a[bar2[bar[b[i].i]]],ch=1;
                else if(bar2[check]==bar[b[i].i] && Max<a[bar2[bar[b[i].i-1]]])Max=a[bar2[bar[b[i].i-1]]],ch=1;
            }

	}
	//if(ch==0)printf("%d\nNo\n",Max);
	printf("%d\nUSE\n",Max);
    return 0;
}
/*
20 5 6
7 5 3 9 4
1 5
1 6
2 10
1 12
3 6
3 13
1

40 5 4
100 150 115 130 90
1 10
2 15
4 20
3 25
3

if(bar[b[i].i]==check || bar[b[i].i+1]==check){
            if(b[i].i+2<=n){
                for(j=1;j<=n;j++){
                    if(bar2[j]==check){
                        if(j==bar[b[i].i+1]&& Max<a[bar2[bar[b[i].i+1]]])Max=a[bar2[bar[b[i].i+1]]],ch=1;
                        else if(j==bar[b[i].i+2]&& Max<a[bar2[bar[b[i].i+2]]])Max=a[bar2[bar[b[i].i+2]]],ch=1;
                    }
                }
            }
            for(j=1;j<=n;j++){
                if(bar2[j]==check){
                    if(j==bar[b[i].i]&& Max<a[bar2[bar[b[i].i]]])Max=a[bar2[bar[b[i].i]]],ch=1;
                    else if(j==bar[b[i].i+1]&& Max<a[bar2[bar[b[i].i+1]]])Max=a[bar2[bar[b[i].i+1]]],ch=1;
                }
            }
            if(b[i].i-1>0){
                for(j=1;j<=n;j++){
                    if(bar2[j]==check){
                        if(j==bar[b[i].i]&& Max<a[bar2[bar[b[i].i]]])Max=a[bar2[bar[b[i].i]]],ch=1;
                        else if(j==bar[b[i].i-1]&& Max<a[bar2[bar[b[i].i-1]]])Max=a[bar2[bar[b[i].i-1]]],ch=1;
                    }
                }
            }
        }
*/
