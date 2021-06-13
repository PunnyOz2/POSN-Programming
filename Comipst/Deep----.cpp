/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int s, a, b;
int dir() {
 int res = ((s & 8) >> 3);
 s = (s * a + b) % 40507;
 return res;
}

int main()
{
    s=100,a=10,b=1;
    printf("%d\n",dir());
    return 0;
}
