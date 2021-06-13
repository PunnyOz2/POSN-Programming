/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int state,now,c=1,ch;
deque<int> xa,ya,za;
void play(int n,int x,int y,int z){
    if(ch==0)return;
    if(n==1){
        now++;
        if(x==1 && state!=0){
            if(z==2)
                ya.push_back(xa.back());
            if(z==3)
                za.push_back(xa.back());
            xa.pop_back();
        }
        if(x==2 && state!=0){
            if(z==1)
                xa.push_back(ya.back());
            if(z==3)
                za.push_back(ya.back());
            ya.pop_back();
        }
        if(x==3 && state!=0){
            if(z==1)
                xa.push_back(za.back());
            if(z==2)
                ya.push_back(za.back());
            za.pop_back();
        }
        if( state==0 ||now==state){
            printf("Case %d:\n",c++);
            printf("A: ");
            if(!xa.empty()){
                while(!xa.empty()){
                    printf("%d ",xa.front());
                    xa.pop_front();
                }
                printf("\n");
            }
            else{
                printf("X\n");
            }
            printf("B: ");
            if(!ya.empty()){
                while(!ya.empty()){
                    printf("%d ",ya.front());
                    ya.pop_front();
                }
                printf("\n");
            }
            else{
                printf("X\n");
            }
            printf("C: ");
            if(!za.empty()){
                while(!za.empty()){
                    printf("%d ",za.front());
                    za.pop_front();
                }
                printf("\n");
            }
            else{
                printf("X\n");
            }
        ch=0;
        }
    }
    else{
        play(n-1,x,z,y);
        play(1,x,y,z);

        play(n-1,y,x,z);
    }
}
int main()
{
	int n,q,i;
	scanf("%d",&q);
	while(q--){
        now=0,ch=1;
        scanf("%d %d",&n,&state);
        for(i=n;i>=1;i--)xa.push_back(i);
        play(n,1,2,3);
        while(!za.empty()){
            za.pop_front();
        }
        while(!ya.empty()){
            ya.pop_front();
        }
        while(!xa.empty()){
            xa.pop_front();
        }
	}
    return 0;
}
