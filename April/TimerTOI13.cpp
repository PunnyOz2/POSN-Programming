/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char a[10000100];
int pi[10000100];
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
        scanf(" %c",&a[i]);
        a[i+n]=a[i];
	}
	int j=0;
	for(i=2;i<=n;i++){
        while(j>0 && a[j+1]!=a[i])j=pi[j];
        if(a[j+1]==a[i])j++;
        pi[i]=j;
	}
	 j=0;
	for(i=2;i<=n*2;i++){
        while(j>0 && a[j+1]!=a[i])j=pi[j];
        if(a[j+1]==a[i])j++;
        if(j==n){
            printf("%d\n",i-n);
            break;
        }
	}
    return 0;
}
/*
10
1000000010
*/
