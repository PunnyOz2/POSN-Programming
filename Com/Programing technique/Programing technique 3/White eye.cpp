/*
    TASK:
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
stack<int> tree;
int main()
{
    int q,u,height;
    char a;
    scanf("%d %d",&q,&u);
    int qq = q+u;
    while(qq--){
        scanf(" %c",&a);
        if(a=='A'){
            scanf("%d",&height);
            while(!tree.empty() && height>=tree.top())
                tree.pop();
            tree.push(height);
        }
            else{
                printf("%d\n",tree.size());
            }

    }

    return 0;
}
