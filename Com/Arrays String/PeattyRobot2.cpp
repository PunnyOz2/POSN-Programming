/*
    TASK:
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<stdio.h>
#include<string.h>
int main()
{
    int x=0,y=0,Angle=0;
    char N,S,E,W,Z,i,F,R;
    char a[200];
    scanf("%s",a);
    int len=strlen(a);
    for(i=0;i<len;i++){
        if(a[i]=='N'){
            if(Angle==0){printf("F");Angle=0;}
            else if(Angle==90){printf("RRRF");Angle=0;}
            else if(Angle==180){printf("RRF");Angle=0;}
            else if(Angle==270){printf("RF");Angle=0;}
            y++;
        }
        else if(a[i]=='S'){
            if(Angle==0){printf("RRF");Angle=180;}
            else if(Angle==90){printf("RF");Angle=180;}
            else if(Angle==180){printf("F");Angle=180;}
            else if(Angle==270){printf("RRRF");Angle=180;}
            y--;
        }
        else if(a[i]=='W'){
            if(Angle==0){printf("RRRF");Angle=270;}
            else if(Angle==90){printf("RRF");Angle=270;}
            else if(Angle==180){printf("RF");Angle=270;}
            else if(Angle==270){printf("F");Angle=270;}
            x--;
        }
        else if(a[i]=='E'){
            if(Angle==0){printf("RF");Angle=90;}
            else if(Angle==90){printf("F");Angle=90;}
            else if(Angle==180){printf("RRRF");Angle=90;}
            else if(Angle==270){printf("RRF");Angle=90;}
            x++;
        }
        else if(a[i]=='Z'){
            printf("Z");
            Angle=0;
            x=0;
            y=0;
        }
    }
    return 0;
}
