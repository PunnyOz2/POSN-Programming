/*
    TASK:
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<stdio.h>
#include<math.h>
int main()
{
    int A,N;
    scanf("%d",&A);
    A = A%360;
    if(A>=16 && A<=45){
        printf("7");
    }
    else if(A>=46 && A<=75){
        printf("8");
    }
    else if(A>=76 && A<=105){
        printf("9");
    }
    else if(A>=106 && A<=135){
        printf("10");
    }
    else if(A>=136 && A<=165){
        printf("11");
    }
    else if(A>=166 && A<195){
        printf("12");
    }
    else if(A>=195 && A<=225){
        printf("1");
    }
    else if(A>=226 && A<=255){
        printf("2");
    }
    else if(A>=256 && A<=285){
        printf("3");
    }
    else if(A>=286 && A<=315){
        printf("4");
    }
    else if(A>=316 && A<=345){
        printf("5");
    }
    else{
        printf("6");
    }



    return 0;
}
