#include <stdio.h>
int main (){
    char g;
    printf("Enter your grade: ");
    scanf("%c",&g);
    switch(g)//only int and char
    {
    case 'a':case 'A':printf("Very Good\n");break;
    case 'b':case 'B':printf("Good\n");break;
    case 'c':case 'C':printf("Fair\n");break;
    case 'd':case 'D':printf("Badly\n");break;
    case 'f':case 'F':printf("Fail\n");break;
    default:printf("Try again !!");
    }
    printf("\"See you again next semester\"");


    return 0;
}
