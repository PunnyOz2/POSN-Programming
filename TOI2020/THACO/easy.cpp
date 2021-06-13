#include<bits/stdc++.h>
using namespace std;
char a[100100],b[100100],ans[100100];
int main(){
    int i,left,aa,bb,coua,coub,Max,now;
	scanf(" %s %s",a,b);
	coua=strlen(a);
	coub=strlen(b);
	reverse(a,a+coua);
	reverse(b,b+coub);
	left=0;
    Max=max(coua,coub);
    for(i=0;i<Max;i++){
        aa=a[i]-'0';
        bb=b[i]-'0';
        if(aa<0)aa=0;
        if(bb<0)bb=0;
        now=aa+bb+left;
        left=0;
        if(now>=10)left=1,now-=10;
        ans[i]=now+'0';
    }
    if(left==1)ans[Max]='1',Max++;
    for(i=Max-1;i>=0;i--)printf("%c",ans[i]);
}
/*
*/
