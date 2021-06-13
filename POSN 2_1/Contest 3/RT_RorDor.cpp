/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char s[10100];
int main()
{
	int lena,i,ans;
	scanf(" %s",s);
	lena=strlen(s);
	int p=12000;
	for(i=0;i<lena;i++){
        if(s[i]=='L') p++;
        else if(s[i]=='R') p--;
        else if(s[i]=='B')p+=2;
	}
	ans=p%4;
	if(ans==0)printf("N");
	if(ans==1)printf("W");
	if(ans==2)printf("S");
	if(ans==3)printf("E");
    return 0;
}
