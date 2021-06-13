/*
    TASK:
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<stdio.h>
void check(int x){
    if(x==48){
        printf("You are BNK48 Ota");
    }
    else{
        printf("WHY SO SERIOUS");
    }
}
int main()
{
    int pass;
    printf("Enter you BNK password : ");
    scanf("%d",&pass);
    check(pass);

    return 0;
}
