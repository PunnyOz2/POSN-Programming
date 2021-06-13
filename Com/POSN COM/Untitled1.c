#include <stdio.h>
#include <string.h>
#include <ctype.h>
void main (){
    /*char name[20];
    scanf("%[A-Z ]s",name);
    printf("%s",name);*/

    char name2[20];
    int NO=0;
    scanf("%s",name2);
    int i;
    int L = strlen(name2);
    for(i=0;i<L;i++){
            if(islower(name2[i])==2/* or !=0 */){
                NO=1;
                printf("%d",islower(name2[i]));
                break;
            }

    }
    if(NO==1){printf("Invalid");}
    if(NO==0){printf("%s",name2);}



}
