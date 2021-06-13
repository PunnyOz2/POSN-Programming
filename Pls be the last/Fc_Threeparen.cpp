/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
stack<char> a;
char f[100100];
int main()
{
    int q,len,i;
    scanf("%d",&q);
    while(q--){
        scanf(" %s",f);
        len=strlen(f);
        for(i=0;i<=len;i++){
            if(f[i]=='('){
                a.push('(');
            }
            if(f[i]=='['){
                a.push('[');
            }
            if(f[i]=='{'){
                a.push('{');
            }
            if(f[i]==')'){
                if(a.empty()){printf("no\n");goto jump;}
                if(a.top()!='('){printf("no\n");goto jump;}
                a.pop();
            }
            if(f[i]==']'){
                if(a.empty()){printf("no\n");goto jump;}
                if(a.top()!='['){printf("no\n");goto jump;}
                a.pop();
            }
            if(f[i]=='}'){
                if(a.empty()){printf("no\n");goto jump;}
                if(a.top()!='{'){printf("no\n");goto jump;}
                a.pop();
            }
        }
        if(!a.empty()){printf("no\n");goto jump;}
        printf("yes\n");
        jump:;
        while(!a.empty())a.pop();
    }
    return 0;
}
