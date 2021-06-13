/*
    TASK: Parenthesis
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char a[140];
stack<char> p;
int main()
{
    int q,s,i,ch;
    scanf("%d",&q);
    while(q--){
        ch=1;
        scanf(" %s",a);
        s=strlen(a);
        for(i=0;i<s;i++){
            if(a[i]=='('||a[i]=='[')p.push(a[i]);
            if(a[i]==')'){
                if(!p.empty()){
                    if(p.top()=='['){printf("No\n"),ch=0;break;}
                    else p.pop();
                }
                else {printf("No\n"),ch=0;break;}
            }
            if(a[i]==']'){
                if(!p.empty()){
                    if(p.top()=='('){printf("No\n"),ch=0;break;}
                    else p.pop();
                }
                else {printf("No\n"),ch=0;break;}
            }
        }
        if(ch!=0 && p.empty())printf("Yes\n");
        else{
            while(!p.empty())p.pop();
        }
        for(i=0;i<s;i++)a[i]='\0';
    }
    return 0;
}
/*
3
([])
(([()])))
([()[]()])()
*/
