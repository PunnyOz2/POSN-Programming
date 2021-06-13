/*
    TASK: Parenthesis
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
stack<char> st;
char a[1000];
int main()
{
    int q,len,ch,i;
    scanf("%d",&q);
    while(q--){
        scanf(" %s",a);
        len =strlen(a);
        ch=1;
        for(i=0;i<len;i++){
            if(a[i]=='(' || a[i]=='[')
                st.push(a[i]);
            else{
                if(a[i]==')'&&(st.empty() || st.top()!='(')){
                    ch=0;break;}
                if(a[i]==']'&&(st.empty() || st.top()!='[')){
                    ch=0;break;}
                st.pop();
            }
        }
        if(st.empty() && ch)printf("Yes\n");
        else printf("No\n");
        while(!st.empty())
            st.pop();
    }

    return 0;
}
