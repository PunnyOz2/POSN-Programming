/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char num[1000100],ans[1000100];
map<string,int> mp;
int main()
{
    int n,len,i,j;
    scanf("%d",&n);
    for(j=0;j<n;j++){
        scanf(" %s",num);
        len=strlen(num);
        for(i=0;i<len;i++){
            if(num[i]=='a'||num[i]=='b'||num[i]=='c')num[i]='2';
            else if(num[i]=='d'||num[i]=='e'||num[i]=='f')num[i]='3';
            else if(num[i]=='g'||num[i]=='h'||num[i]=='i')num[i]='4';
            else if(num[i]=='j'||num[i]=='k'||num[i]=='l')num[i]='5';
            else if(num[i]=='m'||num[i]=='n'||num[i]=='o')num[i]='6';
            else if(num[i]=='p'||num[i]=='q'||num[i]=='r'||num[i]=='s')num[i]='7';
            else if(num[i]=='t'||num[i]=='u'||num[i]=='v')num[i]='8';
            else if(num[i]=='w'||num[i]=='x'||num[i]=='y'||num[i]=='z')num[i]='9';
        }
        mp[num]++;
        //printf("%s ",num);
    }
    scanf(" %s",ans);
    printf("%d",mp[ans]);
    return 0;
}
/*
4
dom
fon
game
tom
366
*/
