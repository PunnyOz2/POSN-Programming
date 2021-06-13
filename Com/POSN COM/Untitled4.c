#include <stdio.h>
int main (){
    int c;
    printf("Enter integer 1, 2, or 3: ");
    scanf("%d",&c);
    switch(c)
    {
    case 1:printf("ONE\n");break;
    case 2:printf("TWO\n");break;
    case 3:printf("THREE\n");break;
    default:printf("Out of range");
    }



    return 0;
}
