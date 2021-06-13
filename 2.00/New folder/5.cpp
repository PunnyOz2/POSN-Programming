/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
const float pi = 3.14159265358979323846;
int main()
{
	int q;
	float rad,n,r;
	scanf("%d",&q);
	while(q--){
        scanf("%lf %lf",&n,&r);
        rad=(360.0/n)/2.0;
        printf("%f ",rad);
        printf("%.1f",2*r*r*cos(pi*rad/180.0)*sin(pi*rad/180.0));
	}
    return 0;
}
