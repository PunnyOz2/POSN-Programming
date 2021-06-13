/*
    TASK:
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<stdio.h>
int main()
{
    int i;
    float a[5];
    printf("Standard value : 2.50\n");
    for(i=0;i<5;i++){
        printf("Value %d : ",i+1);
        scanf("%f",&a[i]);
    }
    for(i=0;i<5;i++){
        if(a[i]>=2.50){
            printf("%.2f\n",a[i]);
        };
    }

    return 0;
}
