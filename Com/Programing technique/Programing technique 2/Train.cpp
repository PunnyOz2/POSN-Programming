/*
    TASK: Train
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
list<int> l;
list<int>::iterator it;
char a[10];
int main()
{
    int n,num;
    scanf("%d",&n);
    l.push_back(999);
    it =l.begin();
    while(n--){
        scanf(" %s",a);
        if(!strcmp(a,"call"))//strcmp(a,"call")==0
            printf("%d\n",*it);
        else if(a[0]=='h')      //head
            it = l.begin();
        else if(a[0]=='t'){     //tail
            it = l.end();
            it--;
        }
        else if(a[0]=='n'){     //next
            it++;
            if(it==l.end())it--;
        }
        else if(a[0]=='l'){     //list
            for(list<int>::iterator i=it; i!=l.end();i++)
                printf("%d ",*i);
            printf("\n");
            it = l.end();
            it--;}
        else if(a[0]=='r'){     //remove
            it++;
            if(it==l.end()) it--;
            else{
                it=l.erase(it);
                it--;
            }
        }
        else if(a[0]=='a'){     //add
            scanf("%d",&num);
            l.insert(++it,num);
            it--;it--;
        }
    }
    return 0;
}
