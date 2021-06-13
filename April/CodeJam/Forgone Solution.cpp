#include<bits/stdc++.h>
using namespace std;
char num[120];
char num2[120];
int main()
{
	int q,i,j,a,b,lena,ch;
	scanf("%d",&q);
	for(j=1;j<=q;j++){
        scanf(" %s",num);
        lena=strlen(num);
        printf("Case #%d: ",j);
        for(i=0;i<lena;i++){
            if(num[i]=='4'){
                num2[i]='1';
            }
            else{
                num2[i]='0';
            }
        }
        ch=1;
        for(i=0;i<lena;i++){
            if(num2[i]!='0'){
                ch=0;
                printf("%c",num2[i]);
            }
            else if(ch==0){
                printf("%c",num2[i]);
            }
        }
        printf(" ");
        ch=1;
        for(i=0;i<lena;i++){
            printf("%d",(num[i]-'0')-(num2[i]-'0'));
        }
        printf("\n");
	}
    return 0;
}
