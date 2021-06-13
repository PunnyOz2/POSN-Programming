#include <stdio.h>
int main(){
    int n,i,num,life0,life1,cou0=0,cou1=0,ans;
    scanf("%d",&n);
    life0=life1=n;
    int mark=0;
    for(i=1;i<=2*n;i++){
        scanf("%d",&num);
        if(num%2==0){
            cou0++;
            if(cou0<3){
                life1--;
            }
            else{
                life1-=3;
            }
            cou1=0;
        }
        else{
            cou1++;
            if(cou1<3){
                life0--;
            }
            else{
                life0-=3;
            }
            cou0=0;
        }
        if((life1<=0 || life0<=0) && mark==0){
            ans=num;
            mark=1;
        }
    }
    printf("%d\n%d\n",ans%2,ans);
}
/*
6
7 5 2 4 8 1 3 9 11 12 13 14
*/
