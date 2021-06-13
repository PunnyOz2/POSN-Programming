#include <stdio.h>
void main (){
    int score;
    printf("Score:");
    scanf("%d",&score);
    if(score>=80)
        printf("A");
    else if(score>=70)
        printf("B");
    else if(score>=60)
        printf("C");
    else if(score>=50)
        printf("D");
    else
        printf("fail.......");
    printf("\nSee you again next semester");



    return 0;
}
