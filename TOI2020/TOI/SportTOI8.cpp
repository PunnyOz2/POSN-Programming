#include <stdio.h>
int k;
int mat[120];
void play(int x,int y,int cou){
    if(x==k || y==k){
        for(int i=0;i<cou;i++){
            if(mat[i]==1)printf("W ");
            if(mat[i]==2)printf("L ");
        }
        printf("\n");
        return;
    }
    mat[cou]=1;
    play(x+1,y,cou+1);
    mat[cou]=2;
    play(x,y+1,cou+1);
}
int main(){
    int winx,winy;
    scanf("%d",&k);
    scanf("%d %d",&winx,&winy);
    play(winx,winy,0);

}
/*
2
0
1
*/
