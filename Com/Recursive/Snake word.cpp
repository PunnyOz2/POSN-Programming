/*
    TASK:
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>
char board[100][100];
char b[120];
int mark[30][30];
int di[4]={1,-1,0,0},dj[4]={0,0,1,-1};
int m,n,c,r,ch;
int len;
int ans[150][2];
char s[500];
void snake(int i,int j,int state){
    ans[state][0]=i+1,ans[state][1]=j+1;//input the first answer and sequencing answer
    int k,ii,jj;
    if(state==len-1){//The first state is 0 so this is the stop sign
        for(k=0;k<len;k++)
            printf("%d %d\n",ans[k][0],ans[k][1]);//print answer
        ch=0;
        return;
    }
    for(k=0;k<4;k++){
        ii=i+di[k],jj=j+dj[k];
        if(ii<0||jj<0||ii>=r||jj>=c) continue;
        if(mark[ii][jj]) continue;//everything but 1
        if(s[state+1]!=board[ii][jj]) continue;//check the letter
        mark[ii][jj] = 1;
        snake(ii,jj,state+1);
        mark[ii][jj]=0;
    }

    }
int main()
{
    int i;
    int j;
    int q;
    char b;
    scanf("%d %d",&r,&c);//scan table
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf(" %c",&b);//scan table data
            board[i][j] = toupper(b);//change to uppercase
        }
    }
    scanf("%d",&q); //scan the number of question
    while(q--){
        scanf(" %s",s);//scan the word of desire
        len=strlen(s);//limiter
        for(i=0;i<len;i++)
            s[i] = toupper(s[i]);//change the word to uppercase
        ch=1;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++){
                if(board[i][j]==s[0]){//check where the first letter might be
                    mark[i][j]=1;//reset
                    snake(i,j,0);//to snake
                    mark[i][j]=0;//blockage
                }
            }
            if(ch)printf("No Matching Word\n");//everything but 1
        }
        return 0;
        }


/*3 5
TAEPE
TULAR
STOPW
2
PEATT
HELLOWORLD*/
