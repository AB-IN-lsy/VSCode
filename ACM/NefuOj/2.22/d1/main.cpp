#include<bits/stdc++.h>

struct node{
    int elem;
    struct node* next;
};
void difference(node** LA,node* LB){
    node*pa,*pb,*pre,*q;
    pre=NULL;
    pa=*LA;
    while(pa){
        pb=LB;
        while(pb && pa->elem!=pb->elem)
            pb=pb->next;
        if(pb){
            if(!pre){
                *LA=pa->next;
            }else{
                pre->next=pa->next;
            }
            q=pa;
            pa=pa->next;
            free(q);
        }else{
            pre=pa;
            pa=pa->next;
        }
    }
}
