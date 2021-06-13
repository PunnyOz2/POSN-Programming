/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char a[1000100];
vector<char> ans[1000100];
int last[1000100];
int main()
{
    int i,cou=0,lena,now;
    gets(a);
    lena=strlen(a);
    for(i=0;i<lena;i++){
        if(a[i]=='.')cou++;
        if(a[i]==' ')a[i]='_';
    }
    for(i=0;i<cou;i++){
        ans[i].push_back('a');
    }
    now=0;
    for(i=0;i<lena;i++){
        while(ans[now].back()=='.'){
            now++;
            now%=cou;
        }
        ans[now].push_back(a[i]);
        now++;
        now%=cou;
    }
    int cc;
    for(i=0;i<cou;i++){
        cc=0;
        for(auto x:ans[i]){
            if(cc==0){cc++;continue;}
            printf("%c",x);
        }
        printf("\n");
    }
    return 0;
}
/*
IPW EOLANOTDVTEEYR .LYAONUD..
*/
