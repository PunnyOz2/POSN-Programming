/*
    TASK:
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<stdio.h>
int main()
{
    int n,i;
    int Old,New;
    int Answer=0;

    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&New);
        if(New>=80){
            Answer++;
            Old=New;
        }
        else if(New>=20 && New-Old>=10 && i!=1){
            Answer++;
            Old=New;
        }
        else{
            Old=New;
        }

    }
    printf("%d",Answer);

    return 0;
}
