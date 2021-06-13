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
   int q,d,m,y,varia;
   char month[][200]={"0","January","February","March","April","May","June","July","August","September","October","November","December"};
   scanf("%d",&q);
   while(q--){
    scanf("%d/%d/%d %d",&d,&m,&y,&varia);
    if(d>=1 && d<=31 && m>=1 && m<=12 &&y>=1000&& y<=3000){
    if(varia==2){
        printf("%02d %s, %d",d,month[m],y);
    }
    if(varia==3){
        printf("%s %02d, %d",month[m],d,y);
    }
    if(varia==4){
        printf("%02d %s, %02d",d,month[m],y%100);
    }

   }   else printf("No");
}

}

