/*
TASK: Infix to Postfix
LANG: C
AUTHOR: PeaTT~
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
char stack[20000]={0},a[200];
int main(){
    int i,n,top=-1;
    scanf("%d\n",&n);
	for(i=0;i<n;i++){
		scanf(" %c",&a[0]);
		if(isalnum(a[0])!=0)
			printf("%s ",a);
		else if(a[0]=='('){
			top++;
			stack[top]='(';
		}
		else if(a[0]==')'){
			while(1){
				if(stack[top]=='(')
					break;
				else{
					printf("%c ",stack[top]);
					top--;
				}
			}
			top--;
		}
		else{
			if(a[0]=='^'){
				while(1){
					if(top==-1||stack[top]=='+'||stack[top]=='-'||stack[top]=='*'||stack[top]=='/'||stack[top]=='('){
						top++;
						stack[top]=a[0];
						break;
					}else{
						printf("%c ",stack[top]);
						top--;
					}
				}
			}
			if(a[0]=='*'||a[0]=='/'){
				while(1){
					if(top==-1||stack[top]=='+'||stack[top]=='-'||stack[top]=='('){
						top++;
						stack[top]=a[0];
						break;
					}else{
						printf("%c ",stack[top]);
						top--;
					}
				}
			}
			if(a[0]=='+'||a[0]=='-'){
				while(1){
					if(top==-1||stack[top]=='('){
						top++;
						stack[top]=a[0];
						break;
					}else{
						printf("%c ",stack[top]);
						top--;
					}
				}
			}
		}
	}
	while(top>=0){
		if(stack[top]!='(')
			printf("%c ",stack[top]);
		top--;
	}
	printf("\n");
	return 0;
}
/*
( 2 * 3 ) ^ 4
*/
