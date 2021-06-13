#include<bits/stdc++.h>
using namespace std;
char a[220];
stack<int> q;
int main(){
    int ans=0,len,i;
    scanf(" %s",a);
    len=strlen(a);
    for(i=0;i<len;i++){
        if(a[i]=='(')q.push(1);
        else {
            if(!q.empty()){
                q.pop();
            }
            else ans++;
        }
    }
    printf("%d\n",ans+q.size());
    return 0;
}
/*

*/
