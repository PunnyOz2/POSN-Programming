/*
    TASK:
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<stdio.h>
int main()
{
    int a,b;
    scanf("%d",&a);
    if(a<=0){
        a=a*-1;
        b=a%360;
        if(b==0||b==180||b==360){
            printf("x-axis");
        }
        else if(b==90||b==270){
            printf("y-axis");
        }
        else if(b<90){
            printf("4");
        }
        else if(b<180){
            printf("3");
        }
        else if(b<270){
            printf("2");
        }
        else if(b<360){
            printf("1");
        }
    }
    else if(a>0){
    b=a%360;
    if(b==0||b==180||b==360){
        printf("x-axis");
    }
    else if(b==90||b==270){
        printf("y-axis");
    }
    else if(b<90){
        printf("1");
    }
    else if(b<180){
        printf("2");
    }
    else if(b<270){
        printf("3");
    }
    else if(b<360){
        printf("4");
    }
    }





    return 0;
}
