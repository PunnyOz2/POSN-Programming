/*
    TASK: Mazu
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
stack<char> st;
char a;
int main()
{
    int q;
    scanf("%d",&q);
    while(q--){
        scanf(" %c",&a);
        if(!st.empty() && st.top()==a)
            st.pop();
        else
            st.push(a);
    }
    printf("%d\n",st.size());
    if(st.size()==0)
        printf("empty\n");
    while(!st.empty()){
        printf("%c",st.top()); st.pop();
    }


    return 0;
}
