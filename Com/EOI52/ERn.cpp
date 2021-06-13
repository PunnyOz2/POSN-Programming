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
    for(i=a,j=b;i>=0 && j>=0;i--,j--){
        if(A[i]>B[j])B[j]='A',ch1=0;
        else if(A[i]<B[j]) A[i]='A',ch2=0;
    }
    ch=1;
    for(i=0,ch1=0;i<a;i++){
        if(A[i]!='A'){
            ch=0;
            if(A[i]!='0'||ch1==1)printf("%c",A[i]),ch1=1;
            else if(i==a-1)printf("%c ",A[i]);
        }
    }
    if(ch==1)printf("Ern ");
    ch=1;
    for(i=0,ch1=0;i<b;i++){
        if(B[i]!='A'){
            ch=0;
            if(B[i]!='0'||ch1==1)printf("%c",B[i]),ch1=1;
            else if(i==b-1)printf("%c ",B[i]);
        }
    }
    if(ch==1)printf("Ern ");
    return 0;
}
