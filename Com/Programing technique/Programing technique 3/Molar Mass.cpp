/*
    TASK:
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char a[120];
int b[120];
int main()
{
    int q,i,len,top,w,num;
    scanf("%d",&q);
    while(q--){
        top=-1;
        scanf(" %s",a);
        len = strlen(a);
        for(i=0;i<len;i++){
            if(a[i]=='C'){
                top++;
                b[top]=12;}
            if(a[i]=='H'){
                top++;
                b[top]=1;}
            if(a[i]=='O'){
                top++;
                b[top]=16;}
            if(a[i]=='('){
                top++;
                b[top]=0;}
            if(a[i]=='2' || a[i]=='3' || a[i]=='4' || a[i]=='5' || a[i]=='6' || a[i]=='7' || a[i]=='8' || a[i]=='9'){
                           b[top]*=(a[i]-'0');}
            if(a[i]==')'){
                    num=0;
                while(1){
                    if(b[top]==0){
                       b[top]=num;
                        break;
                        }
                    else{
                    num+=b[top];
                        top--;
                    }
                }
            }
        }
        for(i=top;i>0;i--){
            b[i-1]+=b[i];
        }
        printf("%d",b[0]);
        }
    return 0;
}
