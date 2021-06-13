/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char a[1010],b[1010];
int main()
{
	int lena,lenb,i,cou=0,cou2=0;
	scanf(" %s %s",a,b);
	lena=strlen(a),lenb=strlen(b);
	for(i=0;i<lena;i++){
        if(a[i]=='1')cou++;
	}
	if(cou%2==1)cou++;
	for(i=0;i<lenb;i++){
        if(b[i]=='1')cou2++;
	}
	if(cou>=cou2)printf("YES\n");
	else printf("NO\n");
    return 0;
}
