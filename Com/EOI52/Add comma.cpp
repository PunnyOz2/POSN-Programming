/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char A[120];
int main()
{
	int q,a,i,b;
	scanf("%d",&q);
	while(q--){
        scanf(" %s",A);
        a=strlen(A);
        for(i=0;i<(a%3);i++)printf("%c",A[i]);
        b=a-(a%3);
        for(i=a%3;i<b;i+=3){
            if(a%3!=0 || i!=a%3)printf(",");
            printf("%c%c%c",A[i],A[i+1],A[i+2]);
        }
        for(i=0;i<a;i++)A[i]='\0';
	}
    return 0;
}
