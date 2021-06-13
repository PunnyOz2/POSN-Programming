/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
stack<int> st;
int main()
{
    char p[100];
    int temp,i;
    scanf(" %s",p);
    int s=strlen(p);
    for(i=0;i<s;i++){
        if(isdigit(p[i])){
            st.push(p[i]-'0');
        }
        else{
            if(p[i]=='+'){
                temp=st.top();
                st.pop();
                temp+=st.top();
                st.push(temp);
            }
            if(p[i]=='-'){
                temp=st.top();
                st.pop();
                temp=st.top()-temp;
                st.push(temp);
            }
            if(p[i]=='/'){
                temp=st.top();
                st.pop();
                temp=st.top()/temp;
                st.push(temp);
            }
            if(p[i]=='*'){
                temp=st.top();
                st.pop();
                temp=st.top()*temp;
                st.push(temp);
            }
        }
    }
    printf("%d",st.top());

    return 0;
}
/*
23+8*9+
*/
