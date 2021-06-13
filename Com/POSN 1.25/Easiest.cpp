/*
    TASK: Easiest
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
priority_queue<int> heap;
int main()
{
    int p,num;
    char a;
    scanf("%d",&p);
	while(p--){
        scanf(" %c",&a);
        if(a=='A'){
            scanf("%d",&num);
            heap.push(num*-1);
        }
        else{
            if(heap.empty()) printf("-1\n");
            else{
                printf("%d\n",heap.top()*-1);
                heap.pop();
            }
        }
	}
    return 0;
}
/*
9
A 7
A 3
A 5
A 3
B
A 4
B
B
B
*/
