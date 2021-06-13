/*
    TASK:
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<stdio.h>
int main()
{
    FILE *fp;
    fp = fopen("C:words.txt","r");
    int len=0;
    while(!feof(fp)){
        fscanf(fp,"%s");
        len++;
    }
    printf("%d\n",len);
    fclose(fp);
    return 0;
}
