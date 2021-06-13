#include<bits/stdc++.h>
using namespace std;
char a[100100];
char ans[100100];
int main()
{
	int Q,i,lena,x,y,ii,jj,ch,n,id,j;
	scanf("%d",&Q);
	for(i=1;i<=Q;i++){
        scanf("%d",&n);
        scanf(" %s",a);
        lena=strlen(a);
        printf("Case #%d: ",i);
        for(ii=0;ii<lena;ii++){
            if(a[ii]=='E')ans[ii]='S';
            else if(a[ii]=='S')ans[ii]='E';
            printf("%c",ans[ii]);
        }
        printf("\n");
	}
    return 0;
}
/*
2
2
SE
5
EESSSESE
*/
