/*
    TASK:
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<stdio.h>
#include<string.h>
char a[100];
int main()
{
    int q,i,len,sum;
    scanf("%d",&q);
    while(q--){
        scanf(" %s",a);
        len = strlen(a);
        for(i=0,sum=0;i<len;i++){
            if(a[i]=='M'){ sum+=1000; }
            else if(a[i]=='C'&&a[i+1]=='M'){ sum+=900; i++; }
            else if(a[i]=='D'){ sum+=500; }
            else if(a[i]=='C'&&a[i+1]=='D'){ sum+=400; i++; }
            else if(a[i]=='C'){ sum+=100; }
            else if(a[i]=='X'&&a[i+1]=='C'){ sum+=90; i++; }
            else if(a[i]=='L'){ sum+=50; }
            else if(a[i]=='X'&&a[i+1]=='L'){ sum+=40; i++; }
            else if(a[i]=='X'){ sum+=10; }
            else if(a[i]=='I'&&a[i+1]=='X'){ sum+=9; i++; }
            else if(a[i]=='V'){ sum+=5; }
            else if(a[i]=='I'&&a[i+1]=='V'){ sum+=4; i++; }
            else if(a[i]=='I'){ sum+=1; }
        }
        printf("%d\n",sum);
    }

    return 0;
}
