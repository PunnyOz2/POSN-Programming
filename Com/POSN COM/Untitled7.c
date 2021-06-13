#include <stdio.h>
int main (){
    int n=1;
/*    for(n=1;n<=50;n++){
        if(n%5==0){
            printf("%d ",n);
        }
    };*/
    while(n<=50){
        if(n%5==0){
            printf("%d ",n);
        };
        n++;
    }

    return 0;
}
