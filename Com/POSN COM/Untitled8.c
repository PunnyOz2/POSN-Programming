#include <stdio.h>
int main (){
    int n;
    int i=0;
    scanf("%d",&n);
    do{
        if(i%10==0){
            printf("%d ",i);};


        i++;
    }while(i<=n);
    return 0;
}
