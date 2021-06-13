/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char num[100100];
int main()
{
    int n,q,sum=0,len,i;
    scanf("%d",&q);
    while(q--){
        sum=0;
        scanf(" %s",num);
        len=strlen(num);
        for(i=0;i<len;i++){
            sum*=10;
            sum+=(num[i]-'0');
            sum%=4;
        }
        if(sum%4==0){
            printf("4\n");
        }
        else printf("0\n");
    }
    return 0;
}
