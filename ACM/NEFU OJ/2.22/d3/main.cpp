#include<stdio.h>
#define  MAXSIZE 100 // 线性表的最大长度

typedef int ElemType;//ELEMENT定义为int类型

//定义结构体
typedef struct{
    ElemType data[MAXSIZE];
    int length;
}SqList;

void DifferentSet(SqList *A,SqList *B,SqList *C){
    int i=0;

    int j = 0;
    for (i=0;i<A->length;i++)
    {
        int k = 0;
        for(j=0;j<B->length;j++)
        {
            if(B->data[j] == A->data[i])
            {
                k++;
            }
        }
        if(k==0)
        {

            C->data[C->length++]=A->data[i];
        }

    }
}

void Display(SqList *L){
    	int i;
    	for(i=0;i<L->length;i++)
        printf("%d ",L->data[i]);
	}
void main()
{
	int i,j;
 	int list1_len;
    int list2_len;

    SqList *A = (SqList*)malloc(sizeof(SqList));
    A->length=0;
    scanf("%d",&list1_len);
    for(i=0;i<list1_len;i++)
    {
   		scanf("%d",&A->data[i]);
   		A->length++;
    }

    SqList *B = (SqList*)malloc(sizeof(SqList));
    B->length=0;
    scanf("%d",&list2_len);
    for(i=0;i<list2_len;i++)
    {
   		scanf("%d",&B->data[i]);
   		B->length++;
    }


    SqList *C = (SqList*)malloc(sizeof(SqList));
    C->length=0;
	DifferentSet(A,B,C);
    Display(C);
}
