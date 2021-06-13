/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char A[12],B[12];
int main()
{
    int a,b,i,j,ch,ch1=1,ch2=1;
    scanf(" %s",A);
    scanf(" %s",B);
    a = strlen(A);
    b = strlen(B);
    for(i=a,j=b;i>=0 && j>=0;i--,j--)
        if(A[i]>B[j])B[j]='O',ch1=0;
        else if(A[i]<B[j]) A[i]='O',ch2=0;
	for(i=0,ch=1;i<=a;i++){
        if(A[i]!='O'){
           if(A[i]!='0' && (ch==0 || i==a-1)) printf("%c",A[i]),ch=0;
        }
    }
	if(ch==1) printf("Ern\n");

	for(j=0,ch=1;j<=b;j++){
	     if(B[j]!='O'){
           if(B[j]!='0' && (ch==0 || j==b-1)) printf("%c",B[j]),ch=0;
        }
    }
	if(ch==1) printf("Ern\n");
    return 0;
}
/*
1000
2000
*/
